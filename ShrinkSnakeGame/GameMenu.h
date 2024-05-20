#pragma once
#include "UIBase.h"


class GameMenu : public UIBase
{
public:
	sf::Font text;
	sf::Text score;

public:
	GameMenu(sf::RenderWindow& nowWindow, Game* game);
	void update() override;
	void render(sf::RenderWindow& nowWindow) override;
	void handleInput(sf::RenderWindow& nowWindow, sf::Event event) override;
};

