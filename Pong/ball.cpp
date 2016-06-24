#include "ball.h"
#include <Windows.h>
#include <iostream>
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

	//changing order of statements seemed to help
	if(this->checkCollision(this->player1)){
		//this->velocity.y *= -1;
		this->velocity.x *= -1;
		this->incrementSpeed();
		
	}

	if( this->checkCollision(this->player2)){
		this->incrementSpeed();
		/*std::cout << this->velocity.x;
		std::cout << this->velocity.y;*/
		//this->velocity.y *= -1;
		this->velocity.x *= -1;
		/*std::cout << this->velocity.x;
		std::cout << this->velocity.y;
		std::cout << "\n";*/

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
	this->setStartVelocity();
	//this->velocity.x = speed;
	//this->velocity.y = speed;
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void ball::setStartVelocity(){
	int i = rand();
	if(i <= .25){
		this->velocity.x = speed;
		this->velocity.y = speed;
	}
	else if(i > .25 && i <= .5){
		this->velocity.x = speed;
		this->velocity.y = -speed;
	}
	else if(i > .5 && i <= .75){
		this->velocity.x = -speed;
		this->velocity.y = speed;
	}
	else{
		this->velocity.x = -speed;
		this->velocity.y = -speed;
	}


}
void ball::incrementSpeed(){
	if(this->speed <= 6.0f){
		this->speed+=1;
		if(this->velocity.y < 0)
			this->velocity.y = -speed;
		else
			this->velocity.y = speed;
		this->velocity.x = speed;
		
	}
}
