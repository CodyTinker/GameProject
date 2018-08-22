#ifndef GAME_GAMEINFOUNIT_HPP
#define GAME_GAMEINFOUNIT_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


#include <string>

namespace GameInfo
{
	struct UnitData
	{
		std::string		Name;
		int				Hp;
		int				Strength;
		int				Magic;
		int				Skill;
		int				Luck;
		int				Defense;
		int				Resistance;
		int				Movement;
	};
	class Unit
	{

	public:
		//Unit();
		Unit(sf::Texture& unitPortrait, sf::Texture& mapPortrait);
		Unit(sf::Texture& unitPortrait, sf::Texture& mapPortrait, UnitData stats);

		UnitData		getUnitStats();
		sf::Texture&	getUnitPortraitTexture();

	private:
		UnitData		mUnitStats;
		
		sf::Texture&	mUnitPortrait;
		sf::Texture&	mMapPortrait;

	};
}

#endif //GAME_GAMEINFOUNIT_HPP