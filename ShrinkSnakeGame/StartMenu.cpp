#include "StartMenu.h"
#include "GameMenu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Game.h"
#include "LoadMenu.h"

StartMenu::StartMenu(sf::RenderWindow& nowWindow, Game* game)
{
	//Get game address
	nowGame = game;

	//Get now window information
	sf::Vector2u windowSize = nowWindow.getSize();

	//Start menu UI text init
	text.loadFromFile("E:\\DeveloperKits_And_IDE\\SFML\\Project\\ShrinkSnakeGame\\Output\\x64\\Debug\\Content\\font\\ka1.ttf");

	title.setFont(text);
	title.setFillColor(sf::Color::White);
	title.setString(gameName);
	title.setCharacterSize(70);
	sf::FloatRect textBounds = title.getLocalBounds();
	title.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	title.setPosition(windowSize.x/2.f, windowSize.y / 2.f - 100.f);

	play.setFont(text);
	play.setFillColor(sf::Color::Green);
	play.setString("Play");
	play.setCharacterSize(30);
	textBounds = play.getLocalBounds();
	play.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	play.setPosition(windowSize.x / 2.f, windowSize.y / 2.f + 50.f);

	scorelist.setFont(text);
	scorelist.setFillColor(sf::Color::Blue);
	scorelist.setString("Score List");
	scorelist.setCharacterSize(30);
	textBounds = scorelist.getLocalBounds();
	scorelist.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	scorelist.setPosition(windowSize.x / 2.f, windowSize.y / 2.f + 100.f);

	exit.setFont(text);
	exit.setFillColor(sf::Color::Red);
	exit.setString("Exit");
	exit.setCharacterSize(30);
	textBounds = exit.getLocalBounds();
	exit.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	exit.setPosition(windowSize.x / 2.f, windowSize.y / 2.f + 150.f);

	//Start menu UI music init
	menuLoop.setVolume(10.0f);
	menuLoop.openFromFile("E:\\DeveloperKits_And_IDE\\SFML\\Project\\ShrinkSnakeGame\\Output\\x64\\Debug\\Content\\music\\music_zapsplat_easy_cheesy.mp3");
	menuLoop.play();
	menuLoop.setLoop(true);
	menuHover.setVolume(500.0f);
	menuHover.openFromFile("E:\\DeveloperKits_And_IDE\\SFML\\Project\\ShrinkSnakeGame\\Output\\x64\\Debug\\Content\\music\\menu-screen-mouse-over.wav");
}

StartMenu::~StartMenu()
{
	sf::Time duration = sf::seconds(1.0f);
	sf::Time elapsedTime;
	sf::Clock clock;

	float initVolume = menuLoop.getVolume();
	sf::Uint8 initA = title.getFillColor().a;
	sf::RenderWindow* nowWindow = nowGame->GetWindow();
	while (elapsedTime < duration) {
		//Fade out loop
		float fadeRatio = elapsedTime / duration;
		float volume = 1.0f - fadeRatio;

		menuLoop.setVolume(initVolume * volume);
		
		title.setFillColor(sf::Color(title.getFillColor().r, title.getFillColor().g, title.getFillColor().b, 255 * volume));
		play.setFillColor(sf::Color(play.getFillColor().r, play.getFillColor().g, play.getFillColor().b, 255 * volume));
		scorelist.setFillColor(sf::Color(scorelist.getFillColor().r, scorelist.getFillColor().g, scorelist.getFillColor().b, 255 * volume));
		exit.setFillColor(sf::Color(exit.getFillColor().r, exit.getFillColor().g, exit.getFillColor().b, 255 * volume));

		nowWindow->clear();
		nowWindow->draw(play);
		nowWindow->draw(title);
		nowWindow->draw(scorelist);
		nowWindow->draw(exit);
		nowWindow->display();

		elapsedTime = clock.getElapsedTime();
	}

	menuLoop.setVolume(0.0f);
}

void StartMenu::init()
{

}

void StartMenu::update()
{

}

void StartMenu::render(sf::RenderWindow& nowWindow)
{

	
	if (hoverPlay) {
		//Set the effect of play text when hover text
		float boundOffsetX = -5.f;
		float boundOffsetY = 5.f;

		sf::Vector2u windowSize = nowWindow.getSize();
		play.setPosition(windowSize.x / 2.f + boundOffsetX, windowSize.y / 2.f + 50.f - boundOffsetY);
	}
	else {
		sf::Vector2u windowSize = nowWindow.getSize();
		play.setPosition(windowSize.x / 2.f, windowSize.y / 2.f + 50.f);
	}

	if (hoverScorelist) {
		//Set the effect of play text when hover text
		float boundOffsetX = -5.f;
		float boundOffsetY = 5.f;

		sf::Vector2u windowSize = nowWindow.getSize();
		scorelist.setPosition(windowSize.x / 2.f + boundOffsetX, windowSize.y / 2.f + 100.f - boundOffsetY);
	}
	else {
		sf::Vector2u windowSize = nowWindow.getSize();
		scorelist.setPosition(windowSize.x / 2.f, windowSize.y / 2.f + 100.f);
	}

	if (hoverExit) {
		//Set the effect of play text when hover text
		float boundOffsetX = -5.f;
		float boundOffsetY = 5.f;

		sf::Vector2u windowSize = nowWindow.getSize();
		exit.setPosition(windowSize.x / 2.f + boundOffsetX, windowSize.y / 2.f + 150.f - boundOffsetY);
	}
	else {
		sf::Vector2u windowSize = nowWindow.getSize();
		exit.setPosition(windowSize.x / 2.f, windowSize.y / 2.f + 150.f);
	}

	nowWindow.draw(play);
	nowWindow.draw(title);
	nowWindow.draw(scorelist);
	nowWindow.draw(exit);
}

void StartMenu::handleInput(sf::RenderWindow& nowWindow, sf::Event event)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(nowWindow);
	sf::Vector2f worldPosition = nowWindow.mapPixelToCoords(mousePosition);
	//std::cout << "PositionX: " << worldPosition.x << "PositionY: " << worldPosition.y << std::endl;

	if (play.getGlobalBounds().contains(worldPosition)) {
		if (!hoverPlay)
			menuHover.play();
		hoverPlay = true;
	}
	else {
		hoverPlay = false;
	}

	if (scorelist.getGlobalBounds().contains(worldPosition)) {
		if (!hoverScorelist)
			menuHover.play();
		hoverScorelist = true;
	}
	else {
		hoverScorelist = false;
	}

	if (exit.getGlobalBounds().contains(worldPosition)) {
		if (!hoverExit)
			menuHover.play();
		hoverExit = true;
	}
	else {
		hoverExit = false;
	}

	if (event.type == sf::Event::MouseButtonReleased) 
	{
		if (hoverPlay) {
			std::cout << "Play clicked" << std::endl;

			if (nowGame) {
				std::shared_ptr<UIBase> nextUI;
				nextUI = std::make_shared<LoadMenu>(nowWindow, nowGame);
				nextUI->init();
				nowGame->changeUI(nextUI);
				return;
			}
		}
		if (hoverScorelist)
			std::cout << "Scorelist clicked" << std::endl;
		if (hoverExit) {
			std::cout << "Exit clicked" << std::endl;
			nowWindow.close();
		}
		
	}
}
