#include "map.h"
#include <fstream>
#include <iostream>

Map::Map(){
}

void Map::loadMap(int id){
    _id = id;
    _walls.clear();
    _passage.clear();

	const char* sourceFileName="MAZEDATA.DTA";
	unsigned char ch=0;	
	std::ifstream inf(sourceFileName, std::ios::binary);
	if (!inf) {std::cerr<<"Cant't open file "<<sourceFileName<< std::endl;}

	inf.seekg(512*_id);
	for (int yy=0; yy<16; yy++){
		for (int xx=0; xx<16; xx++){
			inf.read((char*)&ch, sizeof(ch)); _walls.push_back(ch);
		}
	}
	inf.seekg(512*_id +256);
	for (int yy=0; yy<16; yy++){
		for (int xx=0; xx<16; xx++){
			inf.read((char*)&ch, sizeof(ch)); _passage.push_back(ch);
		}
	}
	inf.close();
}

std::vector<unsigned int> Map::getWalls() const{
	return _walls;
}

unsigned int  Map::getPassage(int posX, int posY) {
	return (_passage[16*posY+posX] & 0x55);
}

bool Map::isNonMagic(int posX, int posY) {
	return (_passage[16*posY+posX] & 0x2) != 0;
}
bool Map::isDangerous(int posX, int posY) {
	return (_passage[16*posY+posX] & 0x8) != 0;
}
bool Map::isDarkness(int posX, int posY) {
	return (_passage[16*posY+posX] & 0x20) != 0;
}
bool Map::isSpecial(int posX, int posY) {
	return (_passage[16*posY+posX] & 0x80) != 0;
}

void Map::clearSpecial(int posX, int posY) {
	_passage[16*posY+posX] &= 0x7f;
}

void Map::reset() {
	loadMap(_id);
}