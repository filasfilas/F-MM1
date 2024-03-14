#include "map.h"
//#include "maze00.h"
#include <fstream>
#include <iostream>

Map::Map(){
	//_id =0;

	const char* sourceFileName="MAZEDATA.DTA";
	unsigned char ch=0;	
	std::ifstream inf(sourceFileName, std::ios::binary);
	if (!inf) {std::cerr<<"Cant't open file "<<sourceFileName<< std::endl;}

	for (int id = 0; id< 55; id++) {
		inf.seekg(512*id);
		for (int yy=0; yy<16; yy++){
			for (int xx=0; xx<16; xx++){
				inf.read((char*)&ch, sizeof(ch)); _walls.push_back(ch);
			}
		}
		inf.seekg(512*id +256);
		for (int yy=0; yy<16; yy++){
			for (int xx=0; xx<16; xx++){
				inf.read((char*)&ch, sizeof(ch)); _passage.push_back(ch);
			}
		}
	}
	inf.close();
}

void Map::select(int id){
    _id = id;
	_regionWalls.clear();
	for (int i=0; i<256; i++) {
		_regionWalls.push_back(_walls[256*id + i]);
	}

	loadScripts();
}

std::vector<unsigned int> Map::getWalls() const{
	return _regionWalls;
}

unsigned int  Map::getPassage(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x55);
}

bool Map::isNonMagic(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x2) != 0;
}
bool Map::isDangerous(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x8) != 0;
}
bool Map::isDarkness(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x20) != 0;
}
bool Map::isSpecial(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x80) != 0;
}

void Map::clearSpecial(int posX, int posY) {
	_passage[getOffset(posX, posY)] &= 0x7f;
}

int Map::getOffset(int posX, int posY) {
	return _id*256+16*posY+posX;
}

//to do
void Map::loadScripts() {
	for(int y=0; y<16; y++){
		for(int x=0; x<16; x++){
			if (isSpecial(x,y)) {

			} 
			else {
				_scripts[x][y] = nullptr;
				_constEncounters[x][y] = 0;
			}
		}
	}
	//_scripts[12][0] = Maze00::_scripts [4];

}
