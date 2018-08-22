#ifndef GAME_MAPUNITSTATUSDIALOG_HPP
#define GAME_MAPUNITSTATUSDIALOG_HPP

#include <Game/MapItems/GameInfoUnit.hpp>


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <string>

namespace Map
{
	class UnitStatusDialog : public sf::Drawable, public sf::Transformable
	{

	public:
		UnitStatusDialog(sf::Texture& dialogTexture, sf::Font& dialogFont);
		void changeDisplayUnit(GameInfo::Unit* displayUnit);

		void update(sf::Time dt);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		GameInfo::Unit* mDisplayUnit;

		sf::Sprite		mDialogSprite;
		sf::Sprite		mPortraitSprite;

		sf::Text		mMyUnitName;
		sf::Text		mMyUnitCurrHP;
		sf::Text		mMyUnitMaxHP;


	};
}

#endif //GAME_MAPUNITSTATUSDIALOG_HPP