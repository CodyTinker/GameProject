#ifndef GAME_MAPUNIT_HPP
#define GAME_MAPUNIT_HPP

#include <Game/MapItems/GameInfoUnit.hpp>

#include <GameEngine/Config/ResourceIdentifiers.hpp>
#include <GameEngine/Resources/Animation.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


#include <string>

namespace Map
{
	class Unit : public sf::Drawable, public sf::Transformable
	{

	public:
		Unit(GameInfo::Unit* unit, sf::Texture& unitTexture);

		void update(sf::Time dt);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		GameInfo::Unit*	mMyUnit;
		Animation		mAnimation;


	};
}

#endif //GAME_MAPTILE_HPP