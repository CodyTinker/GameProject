#ifndef ENGINE_ANIMATION_HPP
#define ENGINE_ANIMATION_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>


class Animation : public sf::Drawable, public sf::Transformable
{
	public:
								Animation();
		explicit 				Animation(const sf::Texture& texture);

		void 					setTexture(const sf::Texture& texture);
		const sf::Texture* 		getTexture() const;

		void					setFirstFrame(sf::Vector2i mFrameCoords);
		sf::Vector2i			getFirstFrame() const;

		void					setFrameDividerSize(int dividerSize);
		int						getFrameDividerSize() const;

		void 					setFrameSize(sf::Vector2i mFrameSize);
		sf::Vector2i		 	getFrameSize() const;

		void 					setNumFrames(std::size_t numFrames);
		std::size_t 			getNumFrames() const;

		void 					setAnimateDirection(bool animateRightFlag);
		bool 					getAnimateDirection() const;

		void 					setDuration(sf::Time duration);
		sf::Time 				getDuration() const;

		void 					setRepeating(bool flag);
		bool 					isRepeating() const;

		void 					restart();
		bool 					isFinished() const;

		sf::FloatRect 			getLocalBounds() const;
		sf::FloatRect 			getGlobalBounds() const;

		void 					update(sf::Time dt);


	private:
		void 					draw(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		sf::Sprite 				mSprite;
		sf::Vector2i			mFirstFrameCoords;
		int						mFrameDividerSize;
		sf::Vector2i 			mFrameSize;
		std::size_t 			mNumFrames;
		bool					mAnimateRight;
		std::size_t 			mCurrentFrame;
		sf::Time 				mDuration;
		sf::Time 				mElapsedTime;
		bool 					mRepeat;
};

#endif // ENGINE_ANIMATION_HPP
