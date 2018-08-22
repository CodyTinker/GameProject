#include <Game/MapItems/MapUnitStatusDialog.hpp>

#include <SFML/Graphics/RectangleShape.hpp>

namespace Map
{

	UnitStatusDialog::UnitStatusDialog(sf::Texture& dialogTexture, sf::Font& dialogFont)
		: mDisplayUnit(nullptr)
		, mDialogSprite(dialogTexture)
		, mPortraitSprite()
	{
		mPortraitSprite.setPosition(0, 2);
		mMyUnitName.setPosition(60, 6);
		mMyUnitName.setFont(dialogFont);
		mMyUnitName.setCharacterSize(12);

	}

	void UnitStatusDialog::changeDisplayUnit(GameInfo::Unit* displayUnit)
	{
		mDisplayUnit = displayUnit;
		mPortraitSprite.setTexture(mDisplayUnit->getUnitPortraitTexture());
		mMyUnitName.setString(displayUnit->getUnitStats().Name);
		sf::FloatRect textBounds = mMyUnitName.getLocalBounds();
		mMyUnitName.setOrigin(sf::Vector2f(textBounds.width / 2, textBounds.height / 2));
	}

	void UnitStatusDialog::update(sf::Time dt)
	{
	}

	void UnitStatusDialog::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (mDisplayUnit != nullptr)
		{
			states.transform *= getTransform();
			//sf::RectangleShape menuRect = sf::RectangleShape(sf::Vector2f(80, 40));
			//menuRect.setFillColor(sf::Color::Blue);
			target.draw(mDialogSprite, states);

			target.draw(mPortraitSprite, states);
			target.draw(mMyUnitName, states);
		}
	}
}