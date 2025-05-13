#include "map.h"
#include "mapdata.h"

#include <fstream>
#include <iostream>


Map::Map(){
	//_currentMapId =51;

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

void Map::init (GameModel* gm){
//to do load mazes
	_mazelist.push_back(new Maze00(gm));
	_mazelist.push_back(new Maze01(gm));
	_mazelist.push_back(new Maze02(gm)); 
	_mazelist.push_back(new Maze03(gm));
	_mazelist.push_back(new Maze04(gm)); 
	_mazelist.push_back(new Maze05(gm)); 
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze06(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze07(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze08(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze09(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze10(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze11(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze12(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze13(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze14(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze15(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze16(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze17(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze18(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze19(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze20(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze21(gm));
	_mazelist.push_back(new Maze22(gm));
	_mazelist.push_back(new Maze23(gm));
	_mazelist.push_back(new Maze24(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze25(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze26(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze27(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze28(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze29(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze30(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze31(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze32(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze33(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze34(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze35(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze36(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze37(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze38(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze39(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze40(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze41(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze42(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze43(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze44(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze45(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze46(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze47(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze48(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze49(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze50(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze51(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze52(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze53(gm));
	_mazelist.push_back(nullptr); //	_mazelist.push_back(new Maze54(gm));
}

void Map::select(int id){
    _currentMapId = id;
	_regionWalls.clear();
	for (int i=0; i<256; i++) {
		_regionWalls.push_back(_walls[256*id + i]);
	}
	_regionPassage.clear();
	for (int i=0; i<256; i++) {
		_regionPassage.push_back(_passage[256*id + i]);
	}

	_currentMaze = _mazelist[id];
}

std::vector<unsigned int> Map::getWalls() const{
	return _regionWalls;
}

//to do: rebuild for regionPassage
std::string Map::getPassage(int posX, int posY, DIRECTION dir){
	std::string result="";
	int resultType = -1;
	if ((_walls[getOffset(posX, posY)] &dir) == 0){
	//no wall
		if(((_passage[getOffset(posX, posY)] & 0x55) &dir) ==0){result = "passage";} //no wall, passage
		else{result = "barrier";}	//no wall, no passage
	}else{
	//a wall
		resultType = _mapdata[_currentMapId][32]; //wall, type2
		if(!((_walls[getOffset(posX, posY)] & 0x55)&dir)){resultType = _mapdata[_currentMapId][31];} //wall, type1
		else if(!((_walls[getOffset(posX, posY)] & 0xaa)&dir)){resultType = _mapdata[_currentMapId][30];} //wall, type0


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
	return (_regionPassage[16*posY+posX] & 0x80) != 0;
}

int	 Map::getEncounterRand(){
	return _mapdata[_currentMapId][29];
}

void Map::clearSpecial(int posX, int posY) {
	_regionPassage[16*posY+posX] &= 0x7f;
}

int Map::getOffset(int posX, int posY) {
	return _currentMapId*256+16*posY+posX;
}

bool Map::isDarkMap(){
	return _mapdata[_currentMapId][46]&0x1;
}

void Map::goNextMap (DIRECTION dir) {	//for regions A1-E4 only
	if (_currentMapId <14) return;
	if (_currentMapId >33) return;
	int tmp;
	if (dir == N) tmp=0;
	if (dir == E) tmp=1;
	if (dir == S) tmp=2;
	if (dir == W) tmp=3;
	select((_nextMapId [tmp] [_currentMapId - 14]));
}

void Map::doScript(int posX, int posY, DIRECTION dir){
	if (_currentMaze != nullptr){
    		_currentMaze -> launchScript(posX, posY, dir);
	}
}
