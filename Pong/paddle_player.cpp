
#include "paddle_player.h"


paddle_player::paddle_player(int playerNumber){
	//get paddle image from folder for each player
	this->playerNumber = playerNumber;
	switch(this->playerNumber){
	case 0:
		this->Load("paddle1.png");
		break;
	default:
		this->Load("paddle2.png");
		break;
	}

}
void paddle_player::Update(){
	//movement + speed of paddles
	switch(this->playerNumber){
	case 0:
		this->velocity.y = 3 * sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - 3 * sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
		break;
	default:
		this->velocity.y = 3 * sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - 3 * sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		break;
	}
	Entity::Update();
	//paddle top bot collision, f count must be the same as multiplier above
	if(this->getPosition().y < 0){
		this->move(0, 3.0f);
	}
	if(this->getPosition().y + this->getGlobalBounds().height > 600){
		this->move(0, -3.0f);
	}

}
