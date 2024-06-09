#include "map.h"
#include "mapdata.h"
//#include "maze00.h"
#include <fstream>
#include <iostream>


Map::Map(){
	//_currentMapID =0;

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
    _currentMapID = id;
	_regionWalls.clear();
	for (int i=0; i<256; i++) {
		_regionWalls.push_back(_walls[256*id + i]);
	}

	loadScripts();
}

std::vector<unsigned int> Map::getWalls() const{
	return _regionWalls;
}

std::string Map::getPassage(int posX, int posY, DIRECTION dir){
	std::string result="";
	int resultType = -1;
	if ((_walls[getOffset(posX, posY)] &dir) == 0){
	//no wall
		if(((_passage[getOffset(posX, posY)] & 0x55) &dir) ==0){result = "passage";} //no wall, passage
		else{result = "barrier";}	//no wall, no passage
	}else{
	//a wall
		resultType = _mapdata[_currentMapID][32]; //wall, type2
		if(!((_walls[getOffset(posX, posY)] & 0x55)&dir)){resultType = _mapdata[_currentMapID][31];} //wall, type1
		else if(!((_walls[getOffset(posX, posY)] & 0xaa)&dir)){resultType = _mapdata[_currentMapID][30];} //wall, type0


		//a wall and no passage
		if((_passage[getOffset(posX, posY)] & 0x55)&dir) {
			switch (resultType){
				case 0: result = "solid"; break;
				case 1: result = "locked"; break;
				case 2: result = "too dence"; break;
				case 3: result = "impassable"; break;
				case 4: result = "rough seas"; break;
				case 5: result = "too windy"; break;
			}
		}else{
			//a wall and passage
			result = "passage";
			if (resultType == 4) {result = "rough seas";}
		}
	}
	//std::cout<<result;
	return result; 
}

bool Map::isNonMagic(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x2) != 0;
}
bool Map::isDangerous(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x8) != 0;
}
bool Map::isDarkCell(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x20) != 0;
}
bool Map::isSpecial(int posX, int posY) {
	return (_passage[getOffset(posX, posY)] & 0x80) != 0;
}

int	 Map::getEncounterRand(){
	return _mapdata[_currentMapID][29];
}

void Map::clearSpecial(int posX, int posY) {
	_passage[getOffset(posX, posY)] &= 0x7f;
}

int Map::getOffset(int posX, int posY) {
	return _currentMapID*256+16*posY+posX;
}

bool Map::isDarkMap(){
	return _mapdata[_currentMapID][46]&0x1;
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
