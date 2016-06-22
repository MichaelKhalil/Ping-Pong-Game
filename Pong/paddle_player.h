#pragma once

#include "entity.h"

class paddle_player : public Entity{

public:
	paddle_player(int playerNumber){
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
	void Update(){
		switch(this->playerNumber){
		case 0:
			this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
			break;
		default:
			this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
			break;
		}
		Entity::Update();

	}
private:
	int playerNumber;
};