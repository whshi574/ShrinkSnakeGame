#pragma once
#include "UIBase.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Music.hpp>

class StartMenu: public UIBase
{
public:
	sf::Font text;
	sf::Text title;
	sf::Text play;
	sf::Text scorelist;
	sf::Text exit;
	sf::Music menuLoop;
	sf::Music menuHover;
	std::string gameName = "Constantly Shrinking";
public:
	StartMenu(sf::RenderWindow& nowWindow, Game* game);
	~StartMenu();
	void init() override;
	void update() override;
	void render(sf::RenderWindow& nowWindow) override;
	void handleInput(sf::RenderWindow& nowWindow, sf::Event event) override;

private:
	bool hoverPlay = false;
	bool hoverScorelist = false;
	bool hoverExit = false;
};