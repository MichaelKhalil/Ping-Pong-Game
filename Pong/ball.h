#pragma once

#include "paddle_player.h"
#include "score.h"

class ball : public Entity{

public:
	ball(sf::RenderWindow* window, Score* score1, Score* score2, paddle_player* player1, paddle_player* player2);
	void Update(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);
	void incrementSpeed();
	void setStartVelocity();
private:
	paddle_player* player1;
	paddle_player* player2;
	Score* score1;
	Score* score2;
	int speed;
};