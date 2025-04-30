#pragma once

#include "State.h"
//#include "StateIdentifiers.h"

#include <vector>
#include <memory>

typedef std::unique_ptr<State> StatePtr;

enum StateAction
{
    NONE,
    ADD,
    REPLACE,
    REPLACEALL,
    REMOVE
};


class StateManager
{
	public:
		StateManager();
		
		void	update(float dt);
      	void	draw(float dt);
		void	handleInput(sf::Event& event);

		void	addState(StatePtr state);
        void    replaceState(StatePtr state);
        void    replaceAllStates(StatePtr state);
		void	removeState();

		void	processStateChange();
		bool    isEmpty();
        StatePtr    &getActiveState();
        	


	private:
		std::vector<StatePtr>	_stateStack;
        StatePtr                _newState;
        StateAction             _action;
};

