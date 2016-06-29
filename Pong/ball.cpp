#include "ball.h"
#include "entity.h"
#include "block.h"
#include <Windows.h>
#include <iostream>

ball::ball(sf::RenderWindow* window, Score* score1, Score* score2, paddle_player* player1, paddle_player* player2, block* blockObject, block* blockObject1, block* blockObject2){
	this->player1 = player1;
	this->player2 = player2;
	this->score1 = score1;
	this->score2 = score2;
	this->blockObject = blockObject;
	this->blockObject1 = blockObject1;
	this->blockObject2 = blockObject2;
	this->Load("ball.png");
	this->speed = 1.0f;
	this->Reset(window);
	this->both = false;
	this->buffer = new sf::SoundBuffer();
	this->buffer->loadFromFile("Sounds/blip.wav");
	this->sound = new sf::Sound(*this->buffer);
	this->sound->setBuffer(*this->buffer);
	
}
	

void ball::Update(sf::RenderWindow* window){

	//incrementSpeed needs to be called last on P1 and first on P2, no explanation why...
	if(this->checkCollision(this->player1)){
		this->velocity.x *= -1;
		if(both){
			this->incrementSpeed();
		}
		this->buffer->loadFromFile("Sounds/blip.wav");
		this->sound->play();
		this->both = !this->both;
	}
	//"both" used so that both players have to hit ball at same speed before incrementing
	if( this->checkCollision(this->player2)){
		if(both){
			this->incrementSpeed();
		}
		this->velocity.x *= -1;
		this->buffer->loadFromFile("Sounds/blip.wav");
		this->sound->play();
		this->both = !this->both;
	}

	if( this->checkCollision(this->blockObject)){
	//	if(this->getPosition().x <= this->blockObject->getPosition().x && this->getPosition().y <= this->blockObject->getPosition().y ){

	//	}
		this->velocity.x *= -1;
		this->blockObject->setPosition(-100,-100);
	}
		if( this->checkCollision(this->blockObject1)){
		this->velocity.x *= -1;
		this->blockObject1->setPosition(-100,-100);
	}
	if( this->checkCollision(this->blockObject2)){
		this->velocity.x *= -1;
		this->blockObject2->setPosition(-100,-100);
	}


	//ball collision with top and bottom walls
	if(this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y){
		this->velocity.y *= -1;
	}
	//if P1 misses, give P2 a point. Reset Ball
	if(this->getPosition().x < this->player1->getGlobalBounds().width - 5){
		this->buffer->loadFromFile("Sounds/miss.wav");
		this->sound->play();
		this->score2->IncrementScore();
		this->Reset(window);
	}
	//if P2 misses, give P1 a point. Reset Ball
	if(this->getPosition().x + this->getGlobalBounds().width > window->getSize().x - this->player2->getGlobalBounds().width + 5){
		this->buffer->loadFromFile("Sounds/miss.wav");
		this->sound->play();
		this->score1->IncrementScore();
		this->Reset(window);
	}
	Entity::Update();
}

void ball::Reset(sf::RenderWindow* window){
	//move to middle, set speed back to 1 on reset and shoot ball randomly
	this->speed = 1.0f;
	this->setStartVelocity();
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	this->blockObject->blockReset(0);
	this->blockObject1->blockReset(1);
	this->blockObject2->blockReset(2);
}

void ball::setStartVelocity(){
	//choose a random number, shoot ball to 4 quadrents based on number
	int i = rand()%100;
	std::cout << i;
	std::cout << "\n";
	if(i <= 25){
		this->velocity.x = speed;
		this->velocity.y = speed;
	}
	else if(i > 25 && i <= 50){
		this->velocity.x = speed;
		this->velocity.y = -speed;
	}
	else if(i > 50 && i <= 75){
		this->velocity.x = -speed;
		this->velocity.y = speed;
	}
	else{
		this->velocity.x = -speed;
		this->velocity.y = -speed;
	}
}

void ball::incrementSpeed(){
	//add 1 to speed when paddle hits, cap at 5.
	if(this->speed <= 5.0f){
		this->speed+=1;
		if(this->velocity.y < 0)
			this->velocity.y = -speed; //Keep Y negative to not change direction
		else
			this->velocity.y = speed;
		this->velocity.x = speed;
	}
}

