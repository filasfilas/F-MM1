#include "market.h"

//#include <fstream>
//#include <iostream>




bool Map::isDarkMap(){
	return _mapdata[_currentMapId][46]&0x1;
}

