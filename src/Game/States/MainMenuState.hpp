#ifndef GAME_MAINMENUSTATE_HPP
#define GAME_MAINMENUSTATE_HPP

#include <GameEngine/States/State.hpp>
#include <GameEngine/Resources/Container.hpp>
#include <Game/MenuItems/MainMenuOptionContainer.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MainMenuState : public State
{
public:
	MainMenuState(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(sf::Time dt);
	virtual bool		handleEvent(const sf::Event& event);


private:
	sf::Sprite							mBackgroundSprite;
	GUI::MainMenuOptionContainer		mMenuContainer;
	sf::Text							mText;

	bool				mShowText;
	sf::Time			mTextEffectTime;
};

#endif // GAME_MainMenuState_HPP
