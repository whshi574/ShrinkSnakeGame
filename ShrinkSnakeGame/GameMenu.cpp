#include "GameMenu.h"

GameMenu::GameMenu(sf::RenderWindow& nowWindow, Game* game)
{
	//Get game address
	nowGame = game;

	//Get now window information
	sf::Vector2u windowSize = nowWindow.getSize();

	//Start menu UI text init
	text.loadFromFile("E:\\DeveloperKits_And_IDE\\SFML\\Project\\ShrinkSnakeGame\\Output\\x64\\Debug\\Content\\font\\ARCADECLASSIC.ttf");

	//Set Game UI text info

	score.setFont(text);
	score.setFillColor(sf::Color::White);
	score.setString("Your Score");
	score.setCharacterSize(35);
	sf::FloatRect textBounds = score.getLocalBounds();
	score.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	score.setPosition(windowSize.x - 200.f, 20.f);
}

void GameMenu::update()
{
}

void GameMenu::render(sf::RenderWindow& nowWindow)
{
	nowWindow.draw(score);
}

void GameMenu::handleInput(sf::RenderWindow& nowWindow, sf::Event event)
{
}
