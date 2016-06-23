#pragma once

#include "game_state.h"
#include "paddle_player.h"

class main_game : public tiny_state{
public:

	virtual void Initialize(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window);
	virtual void Render(sf::RenderWindow* window);
	virtual void Destroy(sf::RenderWindow* window);

private:
	paddle_player* player1;
	paddle_player* player2;
};