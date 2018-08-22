#include <Game/MapItems/Tile.hpp>

#include <GameEngine/Config/ResourceIdentifiers.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


namespace Map
{

	Tile::Tile(int x, int y, Tile::Type type, sf::Texture& textureMap)
	: x(x)
	, y(y)
	, type(type) {
		switch (type){
		case Tile::Plain:
			mSprite = sf::Sprite(textureMap);
			//mSprite.setTextureRect(sf::IntRect(1 + (17 * (rand() % 30)), 1 + (17 * (rand() % 30)), 16, 16));
			mSprite.setTextureRect(sf::IntRect(1 + 17, 1 + 0, 16, 16));
			break;
		default:
			break;
		}
        topTile = nullptr;
        rightTile = nullptr;
        bottomTile = nullptr;
        leftTile = nullptr;

		setPosition((float)(x * GAMETILE_SIZE), (float)(y * GAMETILE_SIZE));
	}

	void Tile::setNeighbors(Tile* top, Tile* right, Tile* bottom, Tile* left) {
		topTile = top;
		rightTile = right;
		bottomTile = bottom;
		leftTile = left;
	}

    int Tile::getX() const {
        return x;
    }
    int Tile::getY() const {
        return y;
    }

	void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();
		target.draw(mSprite, states);        
	}

}
