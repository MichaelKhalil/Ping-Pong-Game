#pragma once
#include "paddle_player.h"
#include "score.h"
#include "block.h"
#include <SFML/Audio.hpp>
class ball : public Entity{

public:
	ball(sf::RenderWindow* window, Score* score1, Score* score2, paddle_player* player1, paddle_player* player2, block* blockObject, block* blockObject1, block* blockObject2);
	void Update(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);
	void incrementSpeed();
	void setStartVelocity();
	void destroyBlock(block* blockObject);

private:
	paddle_player* player1;
	paddle_player* player2;
	Score* score1;
	Score* score2;
	block* blockObject;
	block* blockObject1;
	block* blockObject2;
	sf::SoundBuffer* buffer;
	sf::Sound * sound;
	bool destroyed;
	int speed;
	bool both;
};