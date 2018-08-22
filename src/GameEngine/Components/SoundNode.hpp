#ifndef ENGINE_SOUNDNODE_HPP
#define ENGINE_SOUNDNODE_HPP

#include <GameEngine/Components/SceneNode.hpp>
#include <GameEngine/Config/ResourceIdentifiers.hpp>


class SoundPlayer;

class SoundNode : public SceneNode
{
	public:
		explicit				SoundNode(SoundPlayer& player);
		void					playSound(SoundEffect::ID sound, sf::Vector2f position);

		virtual unsigned int	getCategory() const;


	private:
		SoundPlayer&			mSounds;
};

#endif // ENGINE_SOUNDNODE_HPP
