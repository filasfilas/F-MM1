#include "roster.h"
#include <fstream>
#include <iostream>

Roster::Roster(){
    loadRosterFile();
}

void Roster::loadRosterFile(){
    std::ifstream file(rosterFileName, std::ios::in | std::ios::binary);
    if(!file){
        std::cerr<<"Cant't open file "<<rosterFileName<< std::endl;
    }
    file.read((char*)&memblock, sizeof(memblock));
    file.close();

    for (int i=0; i<18; i++){
	if (int(memblock[2286 +i]) != 0) {readCharacter(i);}
    }
}

void Roster::deleteCharacter(int id){
	if (id>=_roster.size()) return;
	Character* delChar = _roster[id];
	delete (delChar);
	_roster.erase(_roster.begin()+id);
}

Character* Roster::getCharacter(int id){
	if (id>=_roster.size()) return nullptr;
	return _roster[id];
}

void Roster::readCharacter(int id){
	int shift = 127*id;
	Character* newChar = new Character;
	//read name

        for(int i=0; i<16; i++){
	    if(memblock[shift+i] != 0){ 
		newChar -> _name.push_back(memblock[shift+i]);
	    }
	}

        if(memblock[shift+16] == 1){newChar->_sex = MALE;}
        if(memblock[shift+16] == 2 ){newChar->_sex = FEMALE;}

        if(memblock[shift+17]==1) {newChar->_startAlignment = ALIGN_EVIL;}
        if(memblock[shift+17]==2) {newChar->_startAlignment = ALIGN_NEUTRAL;}
        if(memblock[shift+17]==3) {newChar->_startAlignment = ALIGN_GOOD;}

        if(memblock[shift+18]==1) {newChar->_alignment = ALIGN_EVIL;}
        if(memblock[shift+18]==2) {newChar->_alignment = ALIGN_NEUTRAL;}
        if(memblock[shift+18]==3) {newChar->_alignment = ALIGN_GOOD;}

        if(memblock[shift+19]==1) {newChar->_race = HUMAN;}
        if(memblock[shift+19]==2) {newChar->_race = ELF;}
        if(memblock[shift+19]==3) {newChar->_race = DWARF;}
        if(memblock[shift+19]==4) {newChar->_race = GNOME;}
        if(memblock[shift+19]==5) {newChar->_race = HALF_ORC;}

        if(memblock[shift+20]==1) {newChar->_class = CLASS_KNIGHT;}
        if(memblock[shift+20]==2) {newChar->_class = CLASS_PALADIN;}
        if(memblock[shift+20]==3) {newChar->_class = CLASS_ARCHER;}
        if(memblock[shift+20]==4) {newChar->_class = CLASS_CLERIC;}
        if(memblock[shift+20]==5) {newChar->_class = CLASS_SORCERER;}
        if(memblock[shift+20]==6) {newChar->_class = CLASS_ROBBER;}
        if(memblock[shift+20]==7) {newChar->_class = CLASS_NINJA;}	//MM2 only
        if(memblock[shift+20]==8) {newChar->_class = CLASS_BARBARIAN;}	//MM2 only

        newChar->_intellect._permanent = memblock[shift+21];
        newChar->_intellect._temporary = memblock[shift+22];
        newChar->_might._permanent = memblock[shift+23];
        newChar->_might._temporary = memblock[shift+24];
        newChar->_personality._permanent = memblock[shift+25];
        newChar->_personality._temporary = memblock[shift+26];
        newChar->_endurance._permanent = memblock[shift+27];
        newChar->_endurance._temporary = memblock[shift+28];
        newChar->_speed._permanent = memblock[shift+29];
        newChar->_speed._temporary = memblock[shift+30];
        newChar->_accuracy._permanent = memblock[shift+31];
        newChar->_accuracy._temporary = memblock[shift+32];
        newChar->_luck._permanent = memblock[shift+33];
        newChar->_luck._temporary = memblock[shift+34];
        newChar->_level._permanent = memblock[shift+35];
        newChar->_level._temporary = memblock[shift+36];
        newChar->_age._permanent = memblock[shift+37];
//byte 38??
	newChar->_experience = memblock[shift+39]+256*memblock[shift+40]+256*256*memblock[shift+41]+256*256*256*memblock[shift+42];
	newChar->_SP._temporary = memblock[shift+43]+256*memblock[shift+44];
	newChar->_SP._permanent = memblock[shift+45]+256*memblock[shift+46];
	newChar->_spellLevel._permanent = memblock[shift+47];
	newChar->_spellLevel._temporary = memblock[shift+48];

	newChar->_gems = memblock[shift+49]+256*memblock[shift+50];
	newChar->_HP._temporary = memblock[shift+51]+256*memblock[shift+52];
//bytes 53-54 kind of HP???
	newChar->_HP._permanent = memblock[shift+55]+256*memblock[shift+56];
	newChar->_gold = memblock[shift+57]+256*memblock[shift+58]+256*256*memblock[shift+59];
        newChar->_AC._permanent = memblock[shift+60];
        newChar->_AC._temporary = memblock[shift+61];
	newChar->_food = memblock[shift+62];
	
// to do newChar->_condition = memblock[shift+63];

	for (int i=0; i<6; i++){
		if (memblock[shift+64+i] !=0) newChar->_equipped.push_back(memblock[shift+64+i]);
		if (memblock[shift+70+i] !=0) newChar->_backpack.push_back(memblock[shift+70+i]);
	}

// bytes 76-87 ???
	newChar->_magicResistence._permanent = memblock[shift+88];
	newChar->_magicResistence._temporary = memblock[shift+89];
	newChar->_fireResistence._permanent = memblock[shift+90];
	newChar->_fireResistence._temporary = memblock[shift+91];
	newChar->_coldResistence._permanent = memblock[shift+92];
	newChar->_coldResistence._temporary = memblock[shift+93];
	newChar->_electricityResistence._permanent = memblock[shift+94];
	newChar->_electricityResistence._temporary = memblock[shift+95];
	newChar->_acidResistence._permanent = memblock[shift+96];
	newChar->_acidResistence._temporary = memblock[shift+97];
	newChar->_fearResistence._permanent = memblock[shift+98];
	newChar->_fearResistence._temporary = memblock[shift+99];
	newChar->_poisonResistence._permanent = memblock[shift+100];
	newChar->_poisonResistence._temporary = memblock[shift+101];
	newChar->_sleepResistence._permanent = memblock[shift+102];
	newChar->_sleepResistence._temporary = memblock[shift+103];

	newChar->_damage=memblock[shift+104]+256*memblock[shift+105];	
//bytes 106-107 damage temp?
	newChar->_skills[THIEVERY] = memblock[shift+108];
//bytes 109-111
//not sure	newChar->_town=memblock[shift+112];
//bytes 113-125
//byte 126 is ID in "roster.dta". I see no reason to use it

	_roster.push_back(newChar);
}