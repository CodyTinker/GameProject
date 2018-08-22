#include <Game/States/MainMenuState.hpp>
#include <GameEngine/Utility/Utility.hpp>
#include <GameEngine/Resources/ResourceHolder.hpp>

#include <Game/MenuItems/MainMenuOptionContainer.hpp>
#include <Game/MenuItems/MainMenuOption.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


MainMenuState::MainMenuState(StateStack& stack, Context context)
: State(stack, context)
, mText()
, mShowText(false)
, mTextEffectTime(sf::Time::Zero)
, mMenuContainer(context, Textures::MenuOptionFlair)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	auto playButton = std::make_shared<GUI::MainMenuOption>(context, Textures::MenuOption);
	playButton->setPosition(0, 0);
	playButton->setText("Play");
	playButton->setCallback([this]()
	{
		requestStackPop();
		requestStackPush(States::Map);
	});

	auto optionsButton = std::make_shared<GUI::MainMenuOption>(context, Textures::MenuOption);
	optionsButton->setPosition(0, 35);
	optionsButton->setText("Options");
	optionsButton->setCallback([this]()
	{
		requestStackPop();
		//requestStackPush(States);
	});

	mMenuContainer.pack(playButton);
	mMenuContainer.pack(optionsButton);
	mMenuContainer.setPosition(512-(92*3), 200);
	mMenuContainer.setScale(3.f, 3.f);

	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("Press any key to start");
	centerOrigin(mText);
	mText.setPosition(sf::Vector2f(context.window->getSize() / 2u));
}

void MainMenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	window.draw(mMenuContainer);

	if (mShowText)
		window.draw(mText);
}

bool MainMenuState::update(sf::Time dt)
{
	mTextEffectTime += dt;

	if (mTextEffectTime >= sf::seconds(0.5f))
	{
		//mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}

	return true;
}

bool MainMenuState::handleEvent(const sf::Event& event)
{
	mMenuContainer.handleEvent(event);
	// If any key is pressed, trigger the next screen
	//if (event.type == sf::Event::KeyReleased)
	//{
	//	requestStackPop();
	//	//requestStackPush(States::Menu);
	//}

	return true;
}