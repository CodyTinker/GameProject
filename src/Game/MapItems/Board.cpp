#include <Game/MapItems/Board.hpp>

#include <GameEngine/Utility/Foreach.hpp>
#include <GameEngine/Resources/ResourceHolder.hpp>
#include <GameEngine/Config/ResourceIdentifiers.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>



namespace Map
{
    Board::Board(int width, int height, TextureHolder& textures)
        :width(width)
        , height(height)
        , map() {
        // Construct all map tiles
        map.resize(width);
        for (int xx = 0; xx < width; xx++) {
            for (int yy = 0; yy < height; yy++) {
                map[xx].push_back(Tile(xx, yy, Tile::Type::Plain, textures.get(Textures::TileTextures)));
            }
        }
        // Construct map graph
        // Start with inner tiles
        for (int xx = 0; xx < width; xx++) {
            for (int yy = 0; yy < height; yy++) {
                map[xx][yy].setNeighbors(
                    (yy != 0) ? &map[xx][yy - 1] : nullptr, 
                    (xx != width - 1) ? &map[xx + 1][yy] : nullptr, 
                    (yy != height - 1) ? &map[xx][yy + 1] : nullptr,
                    (xx != 0) ? &map[xx - 1][yy] : nullptr);
            }
        }
    }

    Board::~Board()	{

    }

    int Board::getWidth() const{
        return width;
    }
    int Board::getHeight() const{
        return height;
    }

    void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        for (int xx = 0; xx < width; xx++) {
            for (int yy = 0; yy < height; yy++) {
                target.draw(map[xx][yy], states);
            }
        }
        
        // Debug: Draw gridlines
        for (int xx = 0; xx < width; xx++) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f((float)(xx*GAMETILE_SIZE), (float) 0), sf::Color::Black),
                sf::Vertex(sf::Vector2f((float)(xx*GAMETILE_SIZE), (float)(height * GAMETILE_SIZE)), sf::Color::Black)
            };
            target.draw(line, 2, sf::Lines);
        }
        for (int yy = 0; yy < height; yy++) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f((float) 0, (float)(yy*GAMETILE_SIZE)), sf::Color::Black),
                sf::Vertex(sf::Vector2f((float)(width * GAMETILE_SIZE), (float)(yy*GAMETILE_SIZE)), sf::Color::Black)
            };
            target.draw(line, 2, sf::Lines);
        }
    }
}