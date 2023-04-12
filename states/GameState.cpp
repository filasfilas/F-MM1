#include "MenuState.h"
#include "GameState.h"
//#include "../gui/Utility.h"
//#include <iostream>

GameState::GameState(GlobalDataRef gData) 
: gData(gData)
, _mazeRender(&(gData -> mWindow), SCREEN_WIDTH, SCREEN_HEIGHT)
{
	//gData -> mAssets.loadTexture(Textures::MainMenu, "media/images/MM1-map.png");
	//gData -> mAssets.loadTexture(Textures::MenuButton, "media/images/gui/Button.png");
	
	gData -> mMusic.play(Music::TownTheme);
}

void GameState::init() {
	gData -> mGameModel._map.loadMap(0);
	_mazeRender.chooseMaze(gData -> mGameModel._map.getWalls());
	_xPos = (gData -> mGameModel._posX) +0.5;
	_yPos = (gData -> mGameModel._posY) +0.5;
	_angle = dirToAngle(gData -> mGameModel._direction);
}

void GameState::handleInput(const sf::Event& event)
{
        if (event.type == sf::Event::KeyPressed)
        {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {turn (1);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){turn (-1);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { move(1);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { move(-1);}
	}
}

void GameState::update (float dt)
{
	if (_isTurning){
		_angle += _turnDirection*ANGLE_STEP;
		_movingCounter--;
		if (_movingCounter<=0) {
			_isTurning = false; 
			gData -> mGameModel.setDirection (_nextDirection);
		}
		return;
	}
	if (_isMoving){
		_xPos = _targetX - (_targetX-(gData -> mGameModel._posX))*MOVE_STEP*_movingCounter +0.5;
		_yPos = _targetY - (_targetY-(gData -> mGameModel._posY))*MOVE_STEP*_movingCounter +0.5;
		_movingCounter--;
		if(_movingCounter<=0){
			_isMoving = false;
			gData -> mGameModel.setPosition (_targetX, _targetY);
		}
		return;
	}

	_xPos = (gData -> mGameModel._posX) +0.5;
	_yPos = (gData -> mGameModel._posY) +0.5;
	_angle = dirToAngle(gData -> mGameModel._direction);
}

void GameState::draw(float dt) {
	_mazeRender.render(_xPos, _yPos, _angle);
}

void GameState::turn (int turnDir){
	_turnDirection = turnDir;
	if ((_isMoving)||(_isTurning)) return;
	_isTurning = true;
	DIRECTION dir = gData -> mGameModel._direction;
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
	_movingCounter = int(90/ANGLE_STEP);
}

void GameState::move (int deltaMove){
	if ((_isMoving)||(_isTurning)) return;
	if ( !(gData -> mGameModel.canMove(deltaMove))) return;

	_targetX = gData -> mGameModel._posX;
	_targetY = gData -> mGameModel._posY;
	DIRECTION dir = gData -> mGameModel._direction;
	if (dir == E) {_targetX += deltaMove;}
	if (dir == N) {_targetY += deltaMove;}
	if (dir == W) {_targetX -= deltaMove;}
	if (dir == S) {_targetY -= deltaMove;}
	_movingCounter = int(1/MOVE_STEP); 
	_isMoving = true;
}

int GameState::dirToAngle(const DIRECTION dir){
	if (dir==E) return 0;
	if (dir==N) return 90;
	if (dir==W) return 180;
	if (dir==S) return -90;
}