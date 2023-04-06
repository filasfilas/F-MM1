#include "party.h"
#include <iostream>

Party::Party(){
}

bool Party::addCharacter(Character* newChar){
	if(_party.size()>=PARTY_SIZE) return false;
	_party.push_back(newChar);
	return true;
}

void Party::dismissCharacter(int id){
	if(id>=_party.size()) return;
	_party.erase(_party.begin()+id);
}

Character*  Party::getCharacter(int id){
	if(id>=_party.size()) return nullptr;
	else return _party[id];
}

void Party::swapCharacters(int id1, int id2){
	if (id1==id2) return;
	if((id1>=_party.size())||(id2>=_party.size())) return;
	Character* temp = _party[id1];
	_party[id1] = _party[id2];
	_party[id2]= temp;
}

void Party::share(std::string stockType){
	int total = gatherAll(stockType);
	int average = total / _party.size();
	for (int i=0; i<_party.size(); i++){
		_party[i] -> addStock (stockType, average);
	}	
	for (int i=0; i< total % _party.size(); i++){
		_party[i] -> addStock (stockType, 1);
	}	
}


int Party::gatherAll(std::string stockType){
	int result=0;
	for (int i=0; i<_party.size(); i++){
		result += _party[i] -> giveStock (stockType);
	}
	return result;
}