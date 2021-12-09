#include <SFML/Graphics.hpp>

const uint32_t HEIGHT = 800;
const uint32_t WIDTH = 600;

sf::VideoMode vm(HEIGHT, WIDTH);
sf::RenderWindow window(vm, "Noob Platformer", sf::Style::Default);

sf::Texture tatooineTexture;
sf::Sprite tatooineSprite;

sf::Texture lukeTexture;
sf::Sprite lukeSprite;

void init()
{
	tatooineTexture.loadFromFile("Assets/graphics/tatooine.jpg");
	tatooineSprite.setTexture(tatooineTexture);
	
	lukeTexture.loadFromFile("Assets/graphics/luke.png");
	lukeSprite.setTexture(lukeTexture);
	lukeSprite.setPosition(HEIGHT * 0.25f, WIDTH * 0.75f);
	lukeSprite.setOrigin(lukeTexture.getSize().x / static_cast<float>(2), lukeTexture.getSize().y / static_cast<float>(2));
}

void draw()
{
	window.draw(tatooineSprite);
	window.draw(lukeSprite);
}

void updateInput()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.key.code == sf::Keyboard::Escape ||
			event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

int main()
{
	init();

	while (window.isOpen())
	{
		updateInput();

		window.clear(sf::Color::Black);
		
		draw();
		
		window.display();
	}

	return 0;
}