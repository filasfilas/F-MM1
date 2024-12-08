#include "MenuState.h"
#include "GameState.h"
#include "QuickRefState.h"
//#include "../gui/Utility.h"
#include <iostream>

GameState::GameState(GlobalDataRef gData, int townId) 
: gData(gData)
, _mazeRender(&(gData -> mWindow), gData -> mWindow.getSize().x,  gData -> mWindow.getSize().y)
, _gui(&(gData -> mWindow), gData)
{
	_mode = STANDING;
	_startTownId = townId-1;	
	//gData -> mAssets.loadTexture(Textures::MenuButton, "media/images/gui/Button.png");


	gData -> mMusic.play(Music::TownTheme);
}

void GameState::init() {
///////////////////
	gData -> mGameModel.selectMap(_startTownId);
	_mazeRender.chooseMaze(gData -> mGameModel._map.getWalls(), _startTownId);
	_xPos = (gData -> mGameModel.getPosX()) +0.5;
	_yPos = (gData -> mGameModel.getPosY()) +0.5;
	directionToVector(gData -> mGameModel.getDirection());
}

void GameState::handleInput(const sf::Event& event)
{
	if ((_mode == MOVING)||(_mode == TURNING)) return;
	if (event.type == sf::Event::KeyPressed)
    {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {turn (1); return;}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){turn (-1); return;}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { move(1); return;}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { move(-1); return;}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { 
			gData -> mStates.addState(StatePtr (new QuickRefState(gData)));
			return;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { 
			gData -> mGameModel.rest();
			return;
		}
	}
	_gui.handleInput();
}

void GameState::update (float dt)
{
	if (_mode == TURNING){

      		float oldDirX = _dirX;
      		_dirX = _dirX * cos(ANGLE_STEP) - _turnDirection*_dirY * sin(ANGLE_STEP);
      		_dirY = _turnDirection*oldDirX * sin(ANGLE_STEP) + _dirY * cos(ANGLE_STEP);
      		float oldPlaneX = _planeX;
      		_planeX = _planeX * cos(ANGLE_STEP) - _turnDirection*_planeY * sin(ANGLE_STEP);
      		_planeY = _turnDirection*oldPlaneX * sin(ANGLE_STEP) + _planeY * cos(ANGLE_STEP);

		_movingCounter--;
		if (_movingCounter<=0) {
			_mode = STANDING; 
			if(_turnDirection == -1)	{gData -> mGameModel.turnRight();}
			else if (_turnDirection == 1)	{gData -> mGameModel.turnLeft();}
			_gui.makeStep();
		}
		return;
	}
	if (_mode == MOVING){
		_xPos = _targetX - (_targetX-(gData -> mGameModel.getPosX()))*MOVE_STEP*_movingCounter +0.5;
		_yPos = _targetY - (_targetY-(gData -> mGameModel.getPosY()))*MOVE_STEP*_movingCounter +0.5;
		_movingCounter--;
		if(_movingCounter<=0){
			_mode = STANDING;
			//if (deltaMove == 1) {gData -> mGameModel.moveForward();}
			//else if (deltaMove == -1) {gData -> mGameModel.moveBackward();}
			gData -> mGameModel.setPosition (_targetX, _targetY);
			_mazeRender.chooseMaze(gData -> mGameModel._map.getWalls(), gData -> mGameModel.getMapId());
			_gui.makeStep();
		}
		return;
	}

	_xPos = (gData -> mGameModel.getPosX()) +0.5;
	_yPos = (gData -> mGameModel.getPosY()) +0.5;
	directionToVector(gData -> mGameModel.getDirection());

	_gui.update();
}

void GameState::draw(float dt) {
	//_mazeRender.render(_xPos, _yPos, _angle);
	_mazeRender.render(_xPos, _yPos, _dirX, _dirY, _planeX, _planeY);
	_gui.draw();
}

void GameState::turn (int turnDir){
	if (_mode != STANDING) return;

	_turnDirection = turnDir;
	DIRECTION dir = gData -> mGameModel.getDirection();
	if (turnDir == 1) {
		if (dir == N) {_nextDirection = W;}
		if (dir == W) {_nextDirection = S;}
		if (dir == S) {_nextDirection = E;}
		if (dir == E) {_nextDirection = N;}
	}
	if (turnDir == -1) {
		if (dir == N) {_nextDirection = E;}
		if (dir == E) {_nextDirection = S;}
		if (dir == S) {_nextDirection = W;}
		if (dir == W) {_nextDirection = N;}
	}
	_movingCounter = int(90* (M_PI/180)/ANGLE_STEP);
	_mode = TURNING;
}

void GameState::move (int deltaMove){
	if (_mode != STANDING) return;
	if ( !(gData -> mGameModel.canMove(int(_dirX * deltaMove), int(_dirY * deltaMove)))) return;
	_targetX = gData -> mGameModel.getPosX() + _dirX * deltaMove;
	_targetY = gData -> mGameModel.getPosY() + _dirY * deltaMove;
	_movingCounter = int(1/MOVE_STEP); 
	_mode = MOVING;
}

void GameState::directionToVector(const DIRECTION dir){
	if (dir==E) {_dirX = 1; _dirY = 0; _planeX = 0; _planeY = -FOV;};
	if (dir==N) {_dirX = 0; _dirY = 1; _planeX = FOV; _planeY = 0;};
	if (dir==W) {_dirX = -1; _dirY = 0; _planeX = 0; _planeY = FOV;};
	if (dir==S) {_dirX = 0; _dirY = -1; _planeX = -FOV; _planeY = 0;};
}
