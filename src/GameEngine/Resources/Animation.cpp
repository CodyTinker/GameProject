#include <GameEngine/Resources/Animation.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>


Animation::Animation()
: mSprite()
, mFirstFrameCoords(sf::Vector2i(0,0))
, mFrameDividerSize(0)
, mFrameSize()
, mNumFrames(0)
, mAnimateRight(true)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
{
}

Animation::Animation(const sf::Texture& texture)
: mSprite(texture)
, mFirstFrameCoords(sf::Vector2i(0, 0))
, mFrameDividerSize(0)
, mFrameSize()
, mNumFrames(0)
, mAnimateRight(true)
, mCurrentFrame(0)
, mDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false)
{
}

void Animation::setTexture(const sf::Texture& texture)
{
	mSprite.setTexture(texture);
}

const sf::Texture* Animation::getTexture() const
{
	return mSprite.getTexture();
}

void Animation::setFirstFrame(sf::Vector2i mFrameCoords)
{
	mFirstFrameCoords = mFrameCoords;
}
sf::Vector2i Animation::getFirstFrame() const
{
	return mFirstFrameCoords;
}

void Animation::setFrameDividerSize(int dividerSize)
{
	mFrameDividerSize = dividerSize;
}

int	 Animation::getFrameDividerSize() const
{
	return mFrameDividerSize;
}

void Animation::setFrameSize(sf::Vector2i frameSize)
{
	mFrameSize = frameSize;
}

sf::Vector2i Animation::getFrameSize() const
{
	return mFrameSize;
}

void Animation::setNumFrames(std::size_t numFrames)
{
	mNumFrames = numFrames;
}

std::size_t Animation::getNumFrames() const
{
	return mNumFrames;
}

void Animation::setAnimateDirection(bool animateRightFlag)
{
	mAnimateRight = animateRightFlag;
}

bool Animation::getAnimateDirection() const
{
	return mAnimateRight;
}

void Animation::setDuration(sf::Time duration)
{
	mDuration = duration;
}

sf::Time Animation::getDuration() const
{
	return mDuration;
}

void Animation::setRepeating(bool flag)
{
	mRepeat = flag;
}

bool Animation::isRepeating() const
{
	return mRepeat;
}

void Animation::restart()
{
	mCurrentFrame = 0;
}

bool Animation::isFinished() const
{
	return mCurrentFrame >= mNumFrames;
}

sf::FloatRect Animation::getLocalBounds() const
{
	return sf::FloatRect(getOrigin(), static_cast<sf::Vector2f>(getFrameSize()));
}

sf::FloatRect Animation::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void Animation::update(sf::Time dt)
{
	sf::Time timePerFrame = mDuration / static_cast<float>(mNumFrames);
	mElapsedTime += dt;

	sf::Vector2i textureBounds(mSprite.getTexture()->getSize());
	sf::IntRect textureRect = mSprite.getTextureRect();

	if (mCurrentFrame == 0)
		textureRect = sf::IntRect(mFirstFrameCoords.x, mFirstFrameCoords.y, mFrameSize.x, mFrameSize.y);
	
	// While we have a frame to process
	while (mElapsedTime >= timePerFrame && (mCurrentFrame <= mNumFrames || mRepeat))
	{
		if (mAnimateRight)
		{
			// Move the texture rect right
			textureRect.left += textureRect.width + mFrameDividerSize;

			// If we reach the end of the texture
			if (textureRect.left + textureRect.width > textureBounds.x)
			{
				// Move it down one line
				textureRect.left = 0;
				textureRect.top += textureRect.height + mFrameDividerSize;
			}
		}
		else
		{
			// Move the texture rect right
			textureRect.top += textureRect.height + mFrameDividerSize;

			// If we reach the end of the texture
			if (textureRect.top + textureRect.height > textureBounds.y)
			{
				// Move it right one line
				textureRect.top = 0;
				textureRect.left += textureRect.width + mFrameDividerSize;
			}
		}

		// And progress to next frame
		mElapsedTime -= timePerFrame;
		if (mRepeat)
		{
			mCurrentFrame = (mCurrentFrame + 1) % mNumFrames;

			if (mCurrentFrame == 0)
				textureRect = sf::IntRect(mFirstFrameCoords.x, mFirstFrameCoords.y, mFrameSize.x, mFrameSize.y);
		}
		else
		{
			mCurrentFrame++;
		}
	}

	mSprite.setTextureRect(textureRect);
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
}
