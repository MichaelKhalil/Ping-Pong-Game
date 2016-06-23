#include "ball.h"

ball::ball(paddle_player* player1, paddle_player* player2){
	this->player1 = player1;
	this->player2 = player2;
	this->Load("ball.png");

	this->velocity.x = .75f;
	this->velocity.y = 1.0f;
}
	

void ball::Update(){
	if(this->checkCollision(this->player1) || this->checkCollision(this->player2)){
		this->velocity.x *= -1;
	}
	if(this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > 600){
		this->velocity.y *= -1;
	}
	Entity::Update();
}