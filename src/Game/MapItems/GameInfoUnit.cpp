#include <Game/MapItems/GameInfoUnit.hpp>


namespace GameInfo
{
	//Unit::Unit()
	//	: mUnitPortrait(sf::Texture())
	//	, mMapPortrait(sf::Texture())
	//{
	//	mUnitStats = { "Villager", 10, 0, 0, 0, 0, 0, 0, 4 };
	//}

	Unit::Unit(sf::Texture& unitPortrait, sf::Texture& mapPortrait)
		: mUnitPortrait(unitPortrait)
		, mMapPortrait(mapPortrait)
	{
		mUnitStats = { "Villager", 10, 0, 0, 0, 0, 0, 0, 4 };
	}
	
	Unit::Unit(sf::Texture& unitPortrait, sf::Texture& mapPortrait, UnitData stats)
		: mUnitPortrait(unitPortrait)
		, mMapPortrait(mapPortrait)
		, mUnitStats(stats)
	{
	}

	UnitData Unit::getUnitStats()
	{
		return mUnitStats;
	}

	sf::Texture& Unit::getUnitPortraitTexture()
	{
		return mMapPortrait;
	}

}