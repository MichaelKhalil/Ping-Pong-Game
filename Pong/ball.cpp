#include "ball.h"

ball::ball(Score* score1, Score* score2, paddle_player* player1, paddle_player* player2){
	this->player1 = player1;
	this->player2 = player2;
	this->score1 = score1;
	this->score2 = score2;
	this->Load("ball.png");

	this->velocity.x = 1.0f;
	this->velocity.y = 1.0f;
}
	

void ball::Update(sf::RenderWindow* window){
	if(this->checkCollision(this->player1) || this->checkCollision(this->player2)){
		this->velocity.x *= -1;
	}
	if(this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y){
		this->velocity.y *= -1;
	}
	if(this->getPosition().x < this->player1->getGlobalBounds().width - 5){
		this->score2->IncrementScore();
		this->Reset(window);
	}
	if(this->getPosition().x + this->getGlobalBounds().width > window->getSize().x - this->player2->getGlobalBounds().width + 5){
		this->score1->IncrementScore();
		this->Reset(window);
	}
	Entity::Update();
}

void ball::Reset(sf::RenderWindow* window){
	this->velocity.x = 1.0f;
	this->velocity.y = 1.0f;
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}