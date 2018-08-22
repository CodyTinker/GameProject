#ifndef GAME_MAPTILE_HPP
#define GAME_MAPTILE_HPP

#include <GameEngine/Config/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

constexpr auto GAMETILE_SIZE = 16;

namespace Map {
	class Tile : public sf::Drawable, public sf::Transformable {
	public:
		enum Type {
			Plain,
		};

	public:
		Tile(int x, int y, Tile::Type type, sf::Texture& textureMap);
		void setNeighbors(Tile* top, Tile* right, Tile* bottom, Tile* left);

        int getX() const;
        int getY() const;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		Type		type;
		int			x;
		int			y;
		int			defenseBonus;
		int			avoidBonus;
		sf::Sprite	mSprite;
		Tile* topTile;
		Tile* rightTile;
		Tile* bottomTile;
		Tile* leftTile;

	};
}

#endif //GAME_MAPTILE_HPP