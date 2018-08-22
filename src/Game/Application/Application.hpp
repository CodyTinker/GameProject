#ifndef GAME_APPLICATION_HPP
#define GAME_APPLICATION_HPP

#include <GameEngine/Resources/ResourceHolder.hpp>
#include <GameEngine/Config/ResourceIdentifiers.hpp>
//#include <Player.hpp>
#include <GameEngine/States/StateStack.hpp>
//#include <GameEngine/Resources/MusicPlayer.hpp>
#include <GameEngine/Resources/SoundPlayer.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application
{
	public:
								Application();
		void					run();
		

	private:
		void					processInput();
		void					update(sf::Time dt);
		void					render();

		void					updateStatistics(sf::Time dt);
		void					registerStates();


	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		TextureHolder			mTextures;
	  	FontHolder				mFonts;
		//Player					mPlayer;

		//MusicPlayer				mMusic;
		SoundPlayer				mSounds;
		StateStack				mStateStack;

		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

#endif // GAME_APPLICATION_HPP
