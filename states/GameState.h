#pragma once

#include "../core/State.h"
#include "../core/Application.h"
#include "../model/GameModel.h"
#include "../render/MazeRender.h"

#include "../ResourceIdentifiers.h"
#include "../Definitions.h"
#include "../gui/Button.h"
//#include "SFML/Graphics.hpp"

//#include <string>


class GameState : public State
{
	public:
		GameState (GlobalDataRef gData);

        	void init();
        	void handleInput(const sf::Event& event);
        	void update (float dt);
        	void draw(float dt );
        
		void	stop(){};
		void	resume(){};
		void	pause(){};

	private:
		GlobalDataRef	gData;
		MazeRender _mazeRender;
		float _xPos, _yPos;	//position for render
		int _angle; 		//angle for render
		int _targetX, _targetY;
	
		void turn (int turnDir);
		int dirToAngle(const DIRECTION dir);
		void move (int deltaMove);
		bool _isMoving = false;
		bool _isTurning = false;
		int _turnDirection;
		DIRECTION _nextDirection;
		int _movingCounter;
		const int ANGLE_STEP=3;
		float MOVE_STEP = 0.05;

};
