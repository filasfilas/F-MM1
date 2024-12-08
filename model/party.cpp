#include "party.h"
#include <iostream>

Party::Party(){

//temporary party autoload
	for (int i=0; i<6; i++){
		addCharacter(_roster.getCharacter(i));
	}
//temporary party light
	_protections[PARTY_LIGHT]=256;
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

void Party::save(){
	_roster.saveRosterFile();
}

bool Party::hasLight(bool _spendLight){
	bool result = _protections[PARTY_LIGHT];
	if ((_spendLight)&&(result)) {_protections[PARTY_LIGHT]--;}
	return result;
};

bool Party::hasItem(int itemID){
	for (int i=0; i<_party.size(); i++){
		if(_party[i] -> hasItem(itemID)) {	return true; }
	}
	return false;
}

bool Party::isDead(){
	for (int i=0; i<_party.size(); i++){
		if(!_party[i] -> isDead()) {
			return false;		
		}
	}
	return true;
};

void Party::rest(){
	//clean buffs
	for (int i=0; i++; i<(PARTY_PROTECTION_COUNT-1) ) {
		_protections[i]=0;
	}
	//character rest
	for (int i=0; i++; i< PARTY_SIZE) {
		_party[i] -> rest();
	}
}
