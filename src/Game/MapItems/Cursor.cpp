#include <Game/MapItems/Cursor.hpp>

#include <GameEngine/Config/ResourceIdentifiers.hpp>


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace Map
{

	Cursor::Cursor(sf::Texture& texture)
		: mSprite(texture)
		, mCoordinate(0, 0)
	{
		mSprite.setFrameSize(sf::Vector2i(20, 20));
		mSprite.setNumFrames(4);
		mSprite.setRepeating(true);
		mSprite.setDuration(sf::seconds(.5));
	}

	void Cursor::setCoordinate(int x, int y)
	{
		mCoordinate.x = x;
		mCoordinate.y = y;
		setPosition((float)(x * 16),(float)(y * 16));
	}

	void Cursor::setCoordinate(sf::Vector2i coordinate)
	{
		mCoordinate.x = coordinate.x;
		mCoordinate.y = coordinate.y;
		setPosition((float)(mCoordinate.x * 16), (float)(mCoordinate.y * 16));
	}

	sf::Vector2i Cursor::getCoordinate()
	{
		return mCoordinate;
	}

	void Cursor::update(sf::Time dt)
	{
		mSprite.update(dt);
	}

	void Cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(mSprite, states);
	}
}