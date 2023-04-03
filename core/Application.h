#pragma once

#include <memory>
#include "SFML/Graphics.hpp"

#include "StateManager.h"
#include "ResourceManager.h"
#include "MultiLangManager.h"
#include "MusicPlayer.h"

struct GlobalAppData
{
    sf::RenderWindow    mWindow;
    ResourceManager     mAssets;
    MusicPlayer         mMusic;

	MultiLangManager	mStringsDB;
	StateManager		mStates;
    GameModel           mGameModel;
};

typedef std::shared_ptr<GlobalAppData> GlobalDataRef;

class Application
{
	public:
		Application();
		void	run();

	private:
		void	processInput();
		void	update(float dt);
		void	render(float dt);
		void	loadResources();

		const float     TimePerFrame =1.0f/60.0f;
		GlobalDataRef	gData  = std::make_shared<GlobalAppData>();
              
};
