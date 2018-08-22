#include <Game/States/GameMapState.hpp>
#include <GameEngine/Utility/Utility.hpp>
#include <GameEngine/Resources/ResourceHolder.hpp>


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


GameMapState::GameMapState(StateStack& stack, Context context)
	: State(stack, context)
	, mBoard(Map::Board(32, 32, *context.textures))
	, mCursor(context.textures->get(Textures::MapCursor))
	, mStatusDialog(context.textures->get(Textures::MapUnitStatusDialog), context.fonts->get(Fonts::Main))
	, mMapView(sf::FloatRect(0,0, 240, 160))
{

	mCursor.setOrigin(2, 2);
	mCursorMoveDelay = sf::Time::Zero;
	//mBoard.setScale(5, 5);

	//TextureHolder textures = *context.textures;
	mUnitStats.push_back(GameInfo::Unit(context.textures->get(Textures::ExampleUnit), context.textures->get(Textures::ExampleMapUnitPortrait)));
	
	mUnits.push_back(Map::Unit(&mUnitStats[0], context.textures->get(Textures::ExampleUnit)));
	mUnits[0].setPosition(32, 80);
	
	mStatusDialog.setPosition(8, 8);
	mStatusDialog.changeDisplayUnit(&mUnitStats[0]);
}

void GameMapState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(mMapView);

	window.draw(mBoard);
	for (auto unit = mUnits.begin(); unit < mUnits.end(); unit++)
	{
		window.draw(*unit);
	}
	window.draw(mCursor);

	window.draw(mStatusDialog);
}

bool GameMapState::update(sf::Time dt)
{
	//Move cursor
	//Pending implementation - Note: Consider moving functionality to Cursor class
	if (mCursorMoveDelay == sf::Time::Zero)
	{
		sf::Vector2i cursorPos = mCursor.getCoordinate();
		sf::Vector2f viewCenter = mMapView.getCenter();
		sf::Vector2f viewSize = mMapView.getSize();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (cursorPos.y > 0) { cursorPos.y -= 1; mCursorMoveDelay = sf::seconds(0.05f); }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (cursorPos.y < mBoard.getHeight() - 1) { cursorPos.y += 1; mCursorMoveDelay = sf::seconds(0.05f); }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (cursorPos.x > 0) { cursorPos.x -= 1; mCursorMoveDelay = sf::seconds(0.05f); }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (cursorPos.x < mBoard.getWidth() - 1) { cursorPos.x += 1; mCursorMoveDelay = sf::seconds(0.05f); }
		}
		mCursor.setCoordinate(cursorPos);

		//Readjust view
		if (cursorPos.x > (viewCenter.x / 16) + 4) {
            if (viewCenter.x + (viewSize.x / 2) < mBoard.getWidth() * 16) {
                mMapView.move(16, 0);
            }
		}
		else if (cursorPos.x < (viewCenter.x / 16) - 5) {
            if (viewCenter.x - (viewSize.x / 2) > 0) {
                mMapView.move(-16, 0);
            }
		}

		if (cursorPos.y > (viewCenter.y / 16) + 1) {
            if (viewCenter.y + (viewSize.y / 2) < mBoard.getHeight() * 16) {
                mMapView.move(0, 16);
            }
		}
		else if (cursorPos.y < (viewCenter.y / 16) - 2)	{
            if (viewCenter.y - (viewSize.y / 2) > 0) {
                mMapView.move(0, -16);
            }
		}

		viewCenter = mMapView.getCenter();
		//Readjust character dialog
		if (cursorPos.x > (viewCenter.x / 16))
		{
			mStatusDialog.setPosition(viewCenter.x - viewSize.x / 2 + 8, viewCenter.y - viewSize.y/2 + 8);
		}
		else if (cursorPos.x < (viewCenter.x / 16) )
		{
			mStatusDialog.setPosition(viewCenter.x + viewSize.x / 2 - 8 - 88, viewCenter.y - viewSize.y / 2 + 8);
		}

		//Change status dialog to point to character

		//if (cursorPos.y >(viewCenter.y / 16) )
		//{
		//	mMapView.move(0, 16);
		//}
		//else if (cursorPos.y < (viewCenter.y / 16))
		//{
		//	mMapView.move(0, -16);
		//}
	}
	
	if (mCursorMoveDelay.asSeconds() > 0)
	{
		mCursorMoveDelay -= dt;
	}
	else
	{
		mCursorMoveDelay = sf::Time::Zero;
	}
	mCursor.update(dt);


	for (auto unit = mUnits.begin(); unit < mUnits.end(); unit++)
	{
		unit->update(dt);
	}
	


	//getContext().window->setView(sf::View(sf::FloatRect(0, 0, 256, 171)));

	return true;
}

bool GameMapState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	//if (event.type == sf::Event::KeyReleased)
	//{
	//	requestStackPop();
	//	//requestStackPush(States::Menu);
	//}

	return true;
}