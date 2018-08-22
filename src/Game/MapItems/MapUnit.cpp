#include <Game/MapItems/MapUnit.hpp>

namespace Map
{

	Unit::Unit(GameInfo::Unit* unit, sf::Texture& unitTexture)
		: mAnimation(unitTexture)
	{
		mMyUnit = unit;

		mAnimation.setFirstFrame(sf::Vector2i(0, 0));
		mAnimation.setFrameSize(sf::Vector2i(32,32));
		mAnimation.setFrameDividerSize(1);
		mAnimation.setNumFrames(4);
		mAnimation.setAnimateDirection(false);
		mAnimation.setRepeating(true);
		mAnimation.setDuration(sf::seconds(1.f));

		setOrigin(8, 16);
	}

	void Unit::update(sf::Time dt)
	{
		mAnimation.update(dt);
	}

	void Unit::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(mAnimation, states);
	}
}