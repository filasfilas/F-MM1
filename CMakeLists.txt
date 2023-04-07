cmake_minimum_required(VERSION 3.10)
project (mm1 VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_STANDARD_REQUIRED True)


file(GLOB SRC_FILES
    	*.cpp
	core/*.cpp
   	gui/*.cpp
	model/*.cpp
	states/*.cpp
	)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
link_libraries(-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio)


add_executable(F-MM1 ${SRC_FILES})