#ifndef GAME_MAINMENUOPTIONCONTAINER_HPP
#define GAME_MAINMENUOPTIONCONTAINER_HPP

#include <GameEngine/Resources/Component.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <GameEngine/Config/ResourceIdentifiers.hpp>
#include <GameEngine/States/State.hpp>

#include <vector>
#include <memory>


namespace GUI
{

	class MainMenuOptionContainer : public Component
	{
	public:
		typedef std::shared_ptr<MainMenuOptionContainer> Ptr;


	public:
		MainMenuOptionContainer(State::Context context, Textures::ID optionTexture);

		void				pack(Component::Ptr component);
		void				setFlairTexture(Textures::ID flairTexture);

		virtual bool		isSelectable() const;
		virtual void		handleEvent(const sf::Event& event);



	private:
		virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

		bool				hasSelection() const;
		void				select(std::size_t index);
		void				selectNext();
		void				selectPrevious();


	private:
		std::vector<Component::Ptr>		mChildren;
		int							mSelectedChild;
		sf::Sprite						mMenuFlair;
	};

}

#endif // GAME_MAINMENUOPTIONCONTAINER_HPP