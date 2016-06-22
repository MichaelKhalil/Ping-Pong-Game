#include "main_game.h"
#include "menu.h"

void main_game::Initialize(sf::RenderWindow* window){

}
void main_game::Update(sf::RenderWindow* window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
		coreState.SetState(new menu());
	}
}
void main_game::Render(sf::RenderWindow* window){

}
void main_game::Destroy(sf::RenderWindow* window){

}