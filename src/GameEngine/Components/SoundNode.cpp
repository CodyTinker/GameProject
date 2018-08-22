#include <GameEngine/Components/SoundNode.hpp>
#include <GameEngine/Resources/SoundPlayer.hpp>
#include <GameEngine/Config/Category.hpp>


SoundNode::SoundNode(SoundPlayer& player)
: SceneNode()
, mSounds(player)
{
}

void SoundNode::playSound(SoundEffect::ID sound, sf::Vector2f position)
{
	mSounds.play(sound, position);
}

unsigned int SoundNode::getCategory() const
{
	return Category::SoundEffect;
}
