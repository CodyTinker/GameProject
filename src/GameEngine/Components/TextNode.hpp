#ifndef ENGINE_TEXTNODE_HPP
#define ENGINE_TEXTNODE_HPP

#include <GameEngine/Resources/ResourceHolder.hpp>
#include <GameEngine/Config/ResourceIdentifiers.hpp>
#include <GameEngine/Components/SceneNode.hpp>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class TextNode : public SceneNode
{
	public:
		explicit			TextNode(const FontHolder& fonts, const std::string& text);

		void				setString(const std::string& text);


	private:
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		sf::Text			mText;
};

#endif // ENGINE_TEXTNODE_HPP
