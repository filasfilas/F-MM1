#pragma once
#include <cmath>

#include "../core/State.h"
#include "../core/Application.h"
#include "../model/GameModel.h"
#include "../render/MazeRender.h"

#include "../ResourceIdentifiers.h"
//#include "../Definitions.h"
#include "../gui/Button.h"
//#include "SFML/Graphics.hpp"

//#include <string>


class GameState : public State
{
	public:
		GameState (GlobalDataRef gData, int townId);

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
		int	_startTownId;
		float _xPos, _yPos, _dirX, _dirY, _planeX, _planeY;	//vectors for render
		int _angle; 		//angle for render
		int _targetX, _targetY;
	
		void turn (int turnDir);
		void directionToVector(const DIRECTION dir);
		void move (int deltaMove);
		bool _isMoving = false;
		bool _isTurning = false;
		int _turnDirection;
		DIRECTION _nextDirection;
		int _movingCounter;
		int FOV_ANGLE = 90;	//angle of render view (in degrees)
		const float FOV = tan (FOV_ANGLE/2 * (M_PI/180)); //vector length for Field of view for maze render
		const float ANGLE_STEP=3* (M_PI/180);
		float MOVE_STEP = 0.05;

};
