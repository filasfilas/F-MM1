#include "core/Application.h"
#include <stdexcept>
#include <iostream>

int main() {
	try {
	    	Application app;
    		app.run();
	}
	catch (std::exception& e) {
		std::cout<< std::endl<< "Exception: " << e.what()<< std::endl;
	}
}
