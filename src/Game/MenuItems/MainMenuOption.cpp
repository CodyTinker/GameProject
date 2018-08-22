#include <Game/MenuItems/MainMenuOption.hpp>

#include <GameEngine/Config/ResourceIdentifiers.hpp>
#include <GameEngine/Utility/Utility.hpp>
#include <GameEngine/Resources/SoundPlayer.hpp>
#include <GameEngine/Resources/ResourceHolder.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace GUI
{

	MainMenuOption::MainMenuOption(State::Context context, Textures::ID optionTexture) 
	: mCallback()
	, mSprite(context.textures->get(optionTexture))
	, mText("", context.fonts->get(Fonts::Main), 16)
	, mIsToggle(false)
	, mSounds(*context.sounds)
	{
		sf::FloatRect bounds = mSprite.getLocalBounds();
		mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
	}

	void MainMenuOption::setCallback(Callback callback)
	{
		mCallback = std::move(callback);
	}

	void MainMenuOption::setText(const std::string& text)
	{
		mText.setString(text);
		centerOrigin(mText);
	}

	bool MainMenuOption::isSelectable() const
	{
		return true;
	}
	void MainMenuOption::select()
	{
		Component::select();
	}

	void MainMenuOption::deselect()
	{
		Component::deselect();
	}

	void MainMenuOption::activate()
	{
		Component::activate();

		if (mCallback) { mCallback(); }
		
		deactivate();
	}

	void MainMenuOption::deactivate()
	{
		Component::deactivate();
	}

	void MainMenuOption::handleEvent(const sf::Event& event)
	{
	}

	void MainMenuOption::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(mSprite, states);
		target.draw(mText, states);
	}

}