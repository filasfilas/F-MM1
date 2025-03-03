#include "StateManager.h"

StateManager::StateManager ()
: _mAction (NONE)
{}


StatePtr &StateManager::getActiveState (){
    return _mStateStack.back();
}

void StateManager::addState (StatePtr state){
    _newState = std::move(state);
    _mAction = ADD;
}

void StateManager::replaceState (StatePtr state){
    _newState = std::move(state);
    _mAction = REPLACE;
}

void StateManager::replaceAllStates (StatePtr state){
    _newState = std::move(state);
    _mAction = REPLACEALL;
}

void StateManager::removeState (){
    _mAction = REMOVE;
}

void StateManager::processStateChange (){
    if (_mAction == NONE)
        return;

    if (_mAction == ADD)    {
        if (!_mStateStack.empty())
            _mStateStack.back() -> pause();
            
        _mStateStack.push_back(std::move(_newState));
        _mStateStack.back() -> init();
    }

    if (_mAction == REPLACE)    {
        if (!_mStateStack.empty()) {
			_mStateStack.back() -> stop();
            _mStateStack.pop_back();
		}
            
        _mStateStack.push_back(std::move(_newState));
        _mStateStack.back() -> init();
    }

    if (_mAction == REPLACEALL)    {
        while (!_mStateStack.empty()) {
			_mStateStack.back() -> stop();
            _mStateStack.pop_back();
		}
            
        _mStateStack.push_back(std::move(_newState));
        _mStateStack.back() -> init();
    }

    if (_mAction == REMOVE)    {
        if (!_mStateStack.empty()) {
			_mStateStack.back() -> stop();
            		_mStateStack.pop_back();
		}
        if (!_mStateStack.empty())
            _mStateStack.back() -> resume();
    }
    
    _mAction = NONE;
}


void StateManager::update (float dt) {
//    for (StatePtr state:_mStateStack)
      _mStateStack.back() -> update(dt);
}

void StateManager::draw(float dt) {
	for (auto itr = _mStateStack.begin(); itr != _mStateStack.end(); itr++)	{
    	(*itr) -> draw(dt);
	}
}

void StateManager::handleInput(sf::Event& event) {
//    for (StatePtr &state:_mStateStack)
      _mStateStack.back() -> handleInput(event);
}

bool StateManager::isEmpty() {
    return _mStateStack.empty();
}

void StateManager::stop() {
    while (!_mStateStack.empty()) {
		_mStateStack.back() -> stop();
       	_mStateStack.pop_back();
	}
}

