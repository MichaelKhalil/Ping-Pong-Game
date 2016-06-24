#pragma once

#include "paddle_player.h"
#include "score.h"

class ball : public Entity{

public:
	ball(Score* score1, Score* score2, paddle_player* player1, paddle_player* player2);
	void Update(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);

private:
	paddle_player* player1;
	paddle_player* player2;
	Score* score1;
	Score* score2;
};