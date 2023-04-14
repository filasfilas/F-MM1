#pragma once
#include <string>
#include <vector>

//class Item;

enum Sex { MALE = 0, FEMALE = 1};
enum Alignment {ALIGN_EVIL = -1, ALIGN_NEUTRAL = 0, ALIGN_GOOD = 1};
enum Race { HUMAN = 0, ELF = 1, DWARF = 2, GNOME = 3, HALF_ORC = 4 };

//classes 6 and 7 for MM2 only
enum CharacterClass {
	CLASS_KNIGHT = 0, CLASS_PALADIN = 1, CLASS_ARCHER = 2, CLASS_CLERIC = 3,
	CLASS_SORCERER = 4, CLASS_ROBBER = 5, CLASS_NINJA = 6, CLASS_BARBARIAN = 7
};

enum Attribute {
	MIGHT = 0, INTELLECT = 1, PERSONALITY = 2, ENDURANCE = 3, SPEED = 4,
	ACCURACY = 5, LUCK = 6, TOTAL_ATTRIBUTES = 7
};

//MM2 only
enum Skill {
	THIEVERY = 0, ARMS_MASTER = 1, ATHLETE = 2, CARTOGRAPHER = 3, 
	CRUSADER = 4, DIPLOMAT = 5, GAMBLER =6, GLADIATOR =7, HERO = 8, 
	LINGUIST = 9,	MERCHANT = 10, MOUNTAINEER = 11, NAVIGATOR = 12, 
	PATHFINDER = 13, PICK_POCKET = 14, SOLDIER = 15
};

enum SpellsCategory {
	SPELLCAT_INVALID = -1, SPELLCAT_CLERICAL = 0, SPELLCAT_SORCERER = 1
};

enum Condition {
	GOOD = 0, 
	ASLEEP = 1, BLINDED =2, POISONED = 3, 
	DISEASED = 4, PARALYZED = 5, UNCONSCIOUS = 6,
	DEAD = 7, STONED = 8, ERADICATED = 9
};

class AttributePair {
public:
	int _permanent;
	int _temporary;
	AttributePair();
};

class Character
{
public:
	std::string	_name;
	Sex		_sex;
	Alignment	_alignment;
	Alignment	_startAlignment;
	Race	    	_race;
	CharacterClass	_class;

	AttributePair _might;
	AttributePair _intellect;
	AttributePair _personality;
	AttributePair _endurance;
	AttributePair _speed;
	AttributePair _accuracy;
	AttributePair _luck;	
	AttributePair _level;
	AttributePair _age;

	AttributePair _magicResistence;
	AttributePair _fireResistence;
	AttributePair _coldResistence;
	AttributePair _electricityResistence;
	AttributePair _acidResistence;
	AttributePair _fearResistence;
	AttributePair _poisonResistence;
	AttributePair _sleepResistence;
	AttributePair _energyResistence;

	AttributePair _AC;
	AttributePair _spellLevel;

	int _damage;
	int _damageMissile;
	int _skills[16];
	int _condition;
	bool _spells[100]; //if have the exact spells (spellLvl*10+spellId)
	AttributePair _HP;
	AttributePair _SP;
	unsigned long int _experience;
	int _gold;
	int _gems;
	int _food;
	int _town; //0x00 if member of party
	//int _rosterId;
	std::vector<int> _equipped;
	std::vector<int> _backpack;
	std::vector<int> _equipped_charges;
	std::vector<int> _backpack_charges;	

//methods
	Character();
	void clear();

	//getters
	Condition getWorstCondition() const;
	SpellsCategory getSpellsCategory() const;
	int getStat(Attribute attr, bool baseOnly= false) const;
	int getMaxHP() const;
	int getMaxSP() const;
	int getAge(bool baseOnly= false);
	int getArmorClass(bool baseOnly= false) const;
	int getThievery() const;
	int getCurrentLevel(bool baseOnly= false) const;

	//item functions
	void dropItem(int itemNumber);
	void equipItem(int itemNumber);
	void removeItem(int itemNumber);
	bool takeItem(int newItem);
	int giveItem(int itemNumber);
	void useItem(int itemNumber);

	//gold, food, gems functions
	int getStock (std::string stockType) const; //stockType:  food, gold, gems
	void addStock(std::string stockType, int value);
	int giveStock (std::string stockType, int value); 
	int giveStock (std::string stockType); 

private:
	//modifier for attribute depends on conditions
	int conditionModifier(Attribute attribute) const;
};
