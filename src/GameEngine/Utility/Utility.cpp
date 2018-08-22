#include <GameEngine/Utility/Utility.hpp>
#include <GameEngine/Resources/Animation.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <random>
#include <cmath>
#include <ctime>
#include <cassert>


namespace
{
	std::default_random_engine createRandomEngine()
	{
		auto seed = static_cast<unsigned long>(std::time(nullptr));
		return std::default_random_engine(seed);
	}

	auto RandomEngine = createRandomEngine();
}

std::string toString(sf::Keyboard::Key key)
{
	#define ENGINE_KEYTOSTRING_CASE(KEY) case sf::Keyboard::KEY: return #KEY;

	switch (key)
	{
		ENGINE_KEYTOSTRING_CASE(Unknown)
		ENGINE_KEYTOSTRING_CASE(A)
		ENGINE_KEYTOSTRING_CASE(B)
		ENGINE_KEYTOSTRING_CASE(C)
		ENGINE_KEYTOSTRING_CASE(D)
		ENGINE_KEYTOSTRING_CASE(E)
		ENGINE_KEYTOSTRING_CASE(F)
		ENGINE_KEYTOSTRING_CASE(G)
		ENGINE_KEYTOSTRING_CASE(H)
		ENGINE_KEYTOSTRING_CASE(I)
		ENGINE_KEYTOSTRING_CASE(J)
		ENGINE_KEYTOSTRING_CASE(K)
		ENGINE_KEYTOSTRING_CASE(L)
		ENGINE_KEYTOSTRING_CASE(M)
		ENGINE_KEYTOSTRING_CASE(N)
		ENGINE_KEYTOSTRING_CASE(O)
		ENGINE_KEYTOSTRING_CASE(P)
		ENGINE_KEYTOSTRING_CASE(Q)
		ENGINE_KEYTOSTRING_CASE(R)
		ENGINE_KEYTOSTRING_CASE(S)
		ENGINE_KEYTOSTRING_CASE(T)
		ENGINE_KEYTOSTRING_CASE(U)
		ENGINE_KEYTOSTRING_CASE(V)
		ENGINE_KEYTOSTRING_CASE(W)
		ENGINE_KEYTOSTRING_CASE(X)
		ENGINE_KEYTOSTRING_CASE(Y)
		ENGINE_KEYTOSTRING_CASE(Z)
		ENGINE_KEYTOSTRING_CASE(Num0)
		ENGINE_KEYTOSTRING_CASE(Num1)
		ENGINE_KEYTOSTRING_CASE(Num2)
		ENGINE_KEYTOSTRING_CASE(Num3)
		ENGINE_KEYTOSTRING_CASE(Num4)
		ENGINE_KEYTOSTRING_CASE(Num5)
		ENGINE_KEYTOSTRING_CASE(Num6)
		ENGINE_KEYTOSTRING_CASE(Num7)
		ENGINE_KEYTOSTRING_CASE(Num8)
		ENGINE_KEYTOSTRING_CASE(Num9)
		ENGINE_KEYTOSTRING_CASE(Escape)
		ENGINE_KEYTOSTRING_CASE(LControl)
		ENGINE_KEYTOSTRING_CASE(LShift)
		ENGINE_KEYTOSTRING_CASE(LAlt)
		ENGINE_KEYTOSTRING_CASE(LSystem)
		ENGINE_KEYTOSTRING_CASE(RControl)
		ENGINE_KEYTOSTRING_CASE(RShift)
		ENGINE_KEYTOSTRING_CASE(RAlt)
		ENGINE_KEYTOSTRING_CASE(RSystem)
		ENGINE_KEYTOSTRING_CASE(Menu)
		ENGINE_KEYTOSTRING_CASE(LBracket)
		ENGINE_KEYTOSTRING_CASE(RBracket)
		ENGINE_KEYTOSTRING_CASE(SemiColon)
		ENGINE_KEYTOSTRING_CASE(Comma)
		ENGINE_KEYTOSTRING_CASE(Period)
		ENGINE_KEYTOSTRING_CASE(Quote)
		ENGINE_KEYTOSTRING_CASE(Slash)
		ENGINE_KEYTOSTRING_CASE(BackSlash)
		ENGINE_KEYTOSTRING_CASE(Tilde)
		ENGINE_KEYTOSTRING_CASE(Equal)
		ENGINE_KEYTOSTRING_CASE(Dash)
		ENGINE_KEYTOSTRING_CASE(Space)
		ENGINE_KEYTOSTRING_CASE(Return)
		ENGINE_KEYTOSTRING_CASE(BackSpace)
		ENGINE_KEYTOSTRING_CASE(Tab)
		ENGINE_KEYTOSTRING_CASE(PageUp)
		ENGINE_KEYTOSTRING_CASE(PageDown)
		ENGINE_KEYTOSTRING_CASE(End)
		ENGINE_KEYTOSTRING_CASE(Home)
		ENGINE_KEYTOSTRING_CASE(Insert)
		ENGINE_KEYTOSTRING_CASE(Delete)
		ENGINE_KEYTOSTRING_CASE(Add)
		ENGINE_KEYTOSTRING_CASE(Subtract)
		ENGINE_KEYTOSTRING_CASE(Multiply)
		ENGINE_KEYTOSTRING_CASE(Divide)
		ENGINE_KEYTOSTRING_CASE(Left)
		ENGINE_KEYTOSTRING_CASE(Right)
		ENGINE_KEYTOSTRING_CASE(Up)
		ENGINE_KEYTOSTRING_CASE(Down)
		ENGINE_KEYTOSTRING_CASE(Numpad0)
		ENGINE_KEYTOSTRING_CASE(Numpad1)
		ENGINE_KEYTOSTRING_CASE(Numpad2)
		ENGINE_KEYTOSTRING_CASE(Numpad3)
		ENGINE_KEYTOSTRING_CASE(Numpad4)
		ENGINE_KEYTOSTRING_CASE(Numpad5)
		ENGINE_KEYTOSTRING_CASE(Numpad6)
		ENGINE_KEYTOSTRING_CASE(Numpad7)
		ENGINE_KEYTOSTRING_CASE(Numpad8)
		ENGINE_KEYTOSTRING_CASE(Numpad9)
		ENGINE_KEYTOSTRING_CASE(F1)
		ENGINE_KEYTOSTRING_CASE(F2)
		ENGINE_KEYTOSTRING_CASE(F3)
		ENGINE_KEYTOSTRING_CASE(F4)
		ENGINE_KEYTOSTRING_CASE(F5)
		ENGINE_KEYTOSTRING_CASE(F6)
		ENGINE_KEYTOSTRING_CASE(F7)
		ENGINE_KEYTOSTRING_CASE(F8)
		ENGINE_KEYTOSTRING_CASE(F9)
		ENGINE_KEYTOSTRING_CASE(F10)
		ENGINE_KEYTOSTRING_CASE(F11)
		ENGINE_KEYTOSTRING_CASE(F12)
		ENGINE_KEYTOSTRING_CASE(F13)
		ENGINE_KEYTOSTRING_CASE(F14)
		ENGINE_KEYTOSTRING_CASE(F15)
		ENGINE_KEYTOSTRING_CASE(Pause)
	}

	return "";
}

void centerOrigin(sf::Sprite& sprite)
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(Animation& animation)
{
	sf::FloatRect bounds = animation.getLocalBounds();
	animation.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

float toDegree(float radian)
{
	return 180.f / 3.141592653589793238462643383f * radian;
}

float toRadian(float degree)
{
	return 3.141592653589793238462643383f / 180.f * degree;
}

int randomInt(int exclusiveMax)
{
	std::uniform_int_distribution<> distr(0, exclusiveMax - 1);
	return distr(RandomEngine);
}

float length(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f unitVector(sf::Vector2f vector)
{
	assert(vector != sf::Vector2f(0.f, 0.f));
	return vector / length(vector);
}