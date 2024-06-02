#include "TitleState.h"
#include "MenuState.h"
//#include "headers/Utility.h"
#include <iostream>

TitleState::TitleState(GlobalDataRef gData) : gData(gData)
{
	gData -> mAssets.loadTexture(Textures::IntroBook, "media/images/MM1-book.png");
	gData -> mAssets.loadTexture(Textures::Intro0, "media/images/intro/screen0.png");
	gData -> mAssets.loadTexture(Textures::Intro1, "media/images/intro/screen1.png");
	gData -> mAssets.loadTexture(Textures::Intro2, "media/images/intro/screen2.png");
	gData -> mAssets.loadTexture(Textures::Intro3, "media/images/intro/screen3.png");
	gData -> mAssets.loadTexture(Textures::Intro4, "media/images/intro/screen4.png");
	gData -> mAssets.loadTexture(Textures::Intro5, "media/images/intro/screen5.png");
	gData -> mAssets.loadTexture(Textures::Intro6, "media/images/intro/screen6.png");
	gData -> mAssets.loadTexture(Textures::Intro7, "media/images/intro/screen7.png");
	gData -> mAssets.loadTexture(Textures::Intro8, "media/images/intro/screen8.png");
	gData -> mAssets.loadTexture(Textures::Intro9, "media/images/intro/screen9.png");

	gData -> mMusic.play(Music::MainTheme);
}

void TitleState::init() {
	_background.setTexture (gData -> mAssets.getTexture(Textures::IntroBook));
	_slides[0].setTexture (gData -> mAssets.getTexture(Textures::Intro0));
	_slides[1].setTexture (gData -> mAssets.getTexture(Textures::Intro1));
	_slides[2].setTexture (gData -> mAssets.getTexture(Textures::Intro2));
	_slides[3].setTexture (gData -> mAssets.getTexture(Textures::Intro3));
	_slides[4].setTexture (gData -> mAssets.getTexture(Textures::Intro4));
	_slides[5].setTexture (gData -> mAssets.getTexture(Textures::Intro5));
	_slides[6].setTexture (gData -> mAssets.getTexture(Textures::Intro6));
	_slides[7].setTexture (gData -> mAssets.getTexture(Textures::Intro7));
	_slides[8].setTexture (gData -> mAssets.getTexture(Textures::Intro8));
	_slides[9].setTexture (gData -> mAssets.getTexture(Textures::Intro9));

	sf::VideoMode _videoMode = sf::VideoMode::getDesktopMode();
	gData -> mWindow.create(_videoMode, "", sf::Style::Fullscreen);
	sf::Vector2f scale;

	scale.y = 1.0*(_videoMode.height) / (_background.getTextureRect().height);
	scale.x = scale.y;
	_background.setOrigin(_background.getTextureRect().width/2, _background.getTextureRect().height/2);
	_background.setPosition(_videoMode.width/2 , _videoMode.height/2);
	_background.setScale(scale);

	float bookWidth = _background.getGlobalBounds().width;

	for (int i=0; i<10; i++){
		scale.x = 1.0*(bookWidth -40) / _slides[i].getTextureRect().width;
		scale.y = scale.x;
		_slides[i].setOrigin(_slides[i].getTextureRect().width/2, _slides[i].getTextureRect().height);
		_slides[i].setScale(scale);
		_slides[i].setPosition(_videoMode.width/2, _videoMode.height -5);
	}
	timer =0.0;
	_currentSlide = -1;
}

void TitleState::handleInput(const sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed) { nextSlide();}
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Escape){
			gData -> mStates.replaceState(StatePtr(new MenuState(gData)));
		}
		else {nextSlide();}
	}
}

void TitleState::update (float dt){
	timer += dt;
	if (timer > SLIDE_DELAY) { nextSlide();}
}

void TitleState::draw(float dt){
	gData -> mWindow.draw(_background);
	if ((_currentSlide>=0)&&(_currentSlide<10)){
		gData -> mWindow.draw(_slides[_currentSlide]);
	}
}

void TitleState::stop(){
	gData -> mAssets.deleteTexture(Textures::IntroBook);
	gData -> mAssets.deleteTexture(Textures::Intro0);
	gData -> mAssets.deleteTexture(Textures::Intro1);
	gData -> mAssets.deleteTexture(Textures::Intro2);
	gData -> mAssets.deleteTexture(Textures::Intro3);
	gData -> mAssets.deleteTexture(Textures::Intro4);
	gData -> mAssets.deleteTexture(Textures::Intro5);
	gData -> mAssets.deleteTexture(Textures::Intro6);
	gData -> mAssets.deleteTexture(Textures::Intro7);
	gData -> mAssets.deleteTexture(Textures::Intro8);
	gData -> mAssets.deleteTexture(Textures::Intro9);

//temporary non full screen
	int height = sf::VideoMode::getDesktopMode().height -25;
	int width = sf::VideoMode::getDesktopMode().width;

	width = 800;
	height=600;

    gData -> mWindow.create (sf::VideoMode(width, height), APP_NAME, sf::Style::Close);
	gData -> mWindow.setPosition (sf::Vector2i(0,0));

}

void TitleState::nextSlide (){
	_currentSlide ++;
	timer = 0.0;
	if (_currentSlide <=10) {return;}
	else {
		gData -> mStates.replaceState(StatePtr(new MenuState(gData)));
	}
}
