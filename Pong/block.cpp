
#include "block.h"

block::block(sf::RenderWindow* window){
	this->Load("block.png");
}
void block::Update(){

	Entity::Update();
}

void block::blockReset(int number){
	switch(number){
	case 0:
		setPosition(280, 401);
		break;
	case 1:
		setPosition(400, 180);
		break;
	case 2:
		setPosition(550, 400);
		break;
	}
}


