#pragma once

#include "game_state.h"
#include "paddle_player.h"
#include "ball.h"
#include "score.h"
#include "block.h"

class main_game : public tiny_state{
public:

	virtual void Initialize(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window);
	virtual void Render(sf::RenderWindow* window);
	virtual void Destroy(sf::RenderWindow* window);

private:
	paddle_player* player1;
	paddle_player* player2;
	ball* ballObject;
	
	Score* score1;
	Score* score2;
	sf::Font* font;

	block* blockObject;
	block* blockObject1;
	block* blockObject2;
};