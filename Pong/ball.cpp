#include "ball.h"
#include <Windows.h>
ball::ball(sf::RenderWindow* window, Score* score1, Score* score2, paddle_player* player1, paddle_player* player2){
	this->player1 = player1;
	this->player2 = player2;
	this->score1 = score1;
	this->score2 = score2;
	this->Load("ball.png");
	this->speed = 1.0f;
	this->Reset(window);
	//this->velocity.x = speed;
	//this->velocity.y = speed;
}
	

void ball::Update(sf::RenderWindow* window){

	//changing order of 
	if(this->checkCollision(this->player1)){
		this->velocity.y *= -1;
		this->velocity.x *= -1;
		
		this->incrementSpeed(window);
		
	}
	if( this->checkCollision(this->player2)){
		this->incrementSpeed(window);
		this->velocity.y *= -1;
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
	this->speed = 1.0f;
	this->velocity.x = speed;
	this->velocity.y = speed;
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void ball::incrementSpeed(sf::RenderWindow* window){
	if(speed <= 6.0f){
	this->speed += 1.0f;
	this->velocity.x = speed;
	this->velocity.y = speed;
	}
}