#include "LoadMenu.h"
#include <iostream>
#include <thread>
#include <functional>

LoadMenu::LoadMenu(sf::RenderWindow& nowWindow, Game* game)
{
	//Get game address
	nowGame = game;

	//Get now window information
	sf::Vector2u windowSize = nowWindow.getSize();

	//Start menu UI text init
	text.loadFromFile("E:\\DeveloperKits_And_IDE\\SFML\\Project\\ShrinkSnakeGame\\Output\\x64\\Debug\\Content\\font\\ARCADECLASSIC.ttf");

	if (texSnake.loadFromFile("E:\\DeveloperKits_And_IDE\\SFML\\Project\\ShrinkSnakeGame\\Output\\x64\\Debug\\Content\\images\\SnakeNode.png")) {
		// 创建精灵并设置纹理
		snake.setTexture(texSnake);
		snake.setPosition(100.f, 100.f);
	}
	else {
		// 加载失败的处理
		std::cout << "Warning" << std::endl;
	}
	
	//Set Game UI text info

	load.setFont(text);
	load.setFillColor(sf::Color::White);
	load.setString("Loading");
	load.setCharacterSize(45);
	sf::FloatRect textBounds = load.getLocalBounds();
	load.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	load.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);

	//Load animaition
	std::thread t(&LoadMenu::loadAnimation, this);
	t.detach();
}

void LoadMenu::init()
{
}

void LoadMenu::update()
{
	
}

void LoadMenu::render(sf::RenderWindow& nowWindow)
{
	nowWindow.draw(load);
	nowWindow.draw(snake);
}

void LoadMenu::handleInput(sf::RenderWindow& nowWindow, sf::Event event)
{
}

void LoadMenu::loadAnimation()
{
	sf::Vector2f pos;

	pos.x = load.getPosition().x - 100.f;
	pos.y = load.getPosition().y + 20.f;
	snake.setPosition(pos.x + 5.f, pos.y);

	while (true) {
		// Exectue 1s
		std::this_thread::sleep_for(std::chrono::nanoseconds(500));
		snake.setPosition(snake.getPosition().x + 0.01f, snake.getPosition().y);
	}
}