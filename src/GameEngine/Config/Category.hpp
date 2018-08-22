#ifndef ENGINE_CATEGORY_HPP
#define ENGINE_CATEGORY_HPP


// Entity/scene node category, used to dispatch commands
namespace Category
{
	enum Type
	{
		None = 0,
		SceneLayer			= 1 << 0,
		ParticleSystem		= 1 << 1,
		SoundEffect			= 1 << 2,
	};
}

#endif // ENGINE_CATEGORY_HPP
