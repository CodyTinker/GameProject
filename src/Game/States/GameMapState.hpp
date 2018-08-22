#ifndef GAME_GAMEMAPSTATE_HPP
#define GAME_GAMEMAPSTATE_HPP

#include <Game/MenuItems/MainMenuOptionContainer.hpp>
#include <Game/MapItems/Board.hpp>
#include <Game/MapItems/Cursor.hpp>
#include <Game/MapItems/MapUnit.hpp>
#include <Game/MapItems/MapUnitStatusDialog.hpp>

#include <GameEngine/States/State.hpp>
#include <GameEngine/Resources/Container.hpp>


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/View.hpp>


class GameMapState : public State
{
public:
	GameMapState(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(sf::Time dt);
	virtual bool		handleEvent(const sf::Event& event);


private:
	//Cursor
	Map::Cursor mCursor;
	sf::Time	mCursorMoveDelay;
	//Game board
	Map::Board	mBoard;
	//Units Container
	std::vector<GameInfo::Unit> mUnitStats;
	std::vector<Map::Unit>		mUnits;
	//Dialog boxes
	Map::UnitStatusDialog		mStatusDialog;

	sf::View					mMapView;

};

#endif // GAME_GAMEMAPSTATE_HPP
