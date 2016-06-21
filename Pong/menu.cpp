#include <iostream>
#include "menu.h"

void menu::Initialize(sf::RenderWindow* window){
	std::cout << "init\n";
	this->paused = false;
}
void menu::Update(sf::RenderWindow* window){
	if(paused){

	}
	else{
	}
}
void menu::Render(sf::RenderWindow* window){

}
void menu::Destroy(sf::RenderWindow* window){
	std::cout << "des\n";
}