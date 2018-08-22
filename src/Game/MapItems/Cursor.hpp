#ifndef GAME_MAPCURSOR_HPP
#define GAME_MAPCURSOR_HPP

#include <GameEngine/Config/ResourceIdentifiers.hpp>
#include <GameEngine/Resources/Animation.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>


namespace Map
{
	class Cursor : public sf::Drawable, public sf::Transformable
	{

	public:
		Cursor(sf::Texture& texture);
		void setCoordinate(int x, int y);
		void setCoordinate(sf::Vector2i coordinate);
		sf::Vector2i getCoordinate();
		
		void update(sf::Time dt);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::Vector2i	mCoordinate;
		Animation		mSprite;


	};
}

#endif //GAME_MAPCURSOR_HPP