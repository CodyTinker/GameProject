#ifndef GAME_MAPBOARD_HPP
#define GAME_MAPBOARD_HPP

#include <Game/MapItems/Tile.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>

namespace Map
{
	class Board : public sf::Drawable, public sf::Transformable
	{
	public:
		Board(int width, int height, TextureHolder& textures);
		~Board();
		//bool MoveUnit(int start_x, int start_y, int dest_x, int dest_y);
		int getWidth() const;
		int getHeight() const;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		int width;
		int height;
		std::vector< std::vector< Tile > > map;
		
	};

}

#endif  //GAME_MAPBOARD_HPP