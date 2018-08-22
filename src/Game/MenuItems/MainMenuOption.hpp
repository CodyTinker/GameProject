#ifndef GAME_MAINMENUOPTION_HPP
#define GAME_MAINMENUOPTION_HPP

#include <GameEngine/Resources/Component.hpp>
#include <GameEngine/Config/ResourceIdentifiers.hpp>
#include <GameEngine/States/State.hpp>

#include <GameEngine/Config/ResourceIdentifiers.hpp>
#include <GameEngine/Resources/Button.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace GUI
{

	class MainMenuOption : public Component
	{
	public:
		typedef std::function<void()>		Callback;

	public:
		MainMenuOption(State::Context context, Textures::ID optionTexture);

		void					setCallback(Callback callback);
		void					setText(const std::string& text);

		virtual bool			isSelectable() const;
		virtual void			select();
		virtual void			deselect();

		virtual void			activate();
		virtual void			deactivate();

		virtual void			handleEvent(const sf::Event& event);


	private:
		virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;

		Callback				mCallback;
		sf::Sprite				mSprite;
		sf::Text				mText;
		bool					mIsToggle;
		SoundPlayer&			mSounds;

	};

}

#endif // GAME_MAINMENUOPTION_HPP
