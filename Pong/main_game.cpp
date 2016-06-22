#include "main_game.h"
#include "menu.h"

void main_game::Initialize(sf::RenderWindow* window){
	this->paddle = new paddle_player(0);
	this->paddle->Load("paddle1.png");
}
void main_game::Update(sf::RenderWindow* window){
	this->paddle->Update();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
		coreState.SetState(new menu());
	}

}
void main_game::Render(sf::RenderWindow* window){
	window->draw(*this->paddle);
}
void main_game::Destroy(sf::RenderWindow* window){
	delete this->paddle;
}