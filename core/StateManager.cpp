#include "StateManager.h"

StateManager::StateManager ()
: _action (NONE)
{}


StatePtr &StateManager::getActiveState (){
    return _stateStack.back();
}

void StateManager::addState (StatePtr state){
    _newState = std::move(state);
    _action = ADD;
}

void StateManager::replaceState (StatePtr state){
    _newState = std::move(state);
    _action = REPLACE;
}

void StateManager::replaceAllStates (StatePtr state){
    _newState = std::move(state);
    _action = REPLACEALL;
}

void StateManager::removeState (){
    _action = REMOVE;
}

void StateManager::processStateChange (){
    if (_action == NONE)
        return;

    if (_action == ADD)    {
        if (!_stateStack.empty())
            _stateStack.back() -> pause();
            
        _stateStack.push_back(std::move(_newState));
        _stateStack.back() -> init();
    }

    if (_action == REPLACE)    {
        if (!_stateStack.empty()) {
			_stateStack.back() -> stop();
            		_stateStack.pop_back();
		}
            
        _stateStack.push_back(std::move(_newState));
        _stateStack.back() -> init();
    }

    if (_action == REPLACEALL)    {
        while (!_stateStack.empty()) {
			_stateStack.back() -> stop();
            		_stateStack.pop_back();
		}
            
        _stateStack.push_back(std::move(_newState));
        _stateStack.back() -> init();
    }

    if (_action == REMOVE)    {
        if (!_stateStack.empty()) {
			_stateStack.back() -> stop();
            		_stateStack.pop_back();
		}
        if (!_stateStack.empty())
            _stateStack.back() -> resume();
    }
    
    _action = NONE;
}


void StateManager::update (float dt) {
//    for (StatePtr state:_stateStack)
      _stateStack.back() -> update(dt);
}

void StateManager::draw(float dt) {
	for (auto itr = _stateStack.begin(); itr != _stateStack.end(); itr++)	{
    	(*itr) -> draw(dt);
	}
}

void StateManager::handleInput(sf::Event& event) {
//    for (StatePtr &state:_stateStack)
      _stateStack.back() -> handleInput(event);
}

bool StateManager::isEmpty() {
    return _stateStack.empty();
}

