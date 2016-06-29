#include "main_game.h"
#include "menu.h"
#include "ball.h"
#include "block.h"
void main_game::Initialize(sf::RenderWindow* window){

	this->font = new sf::Font();
	this->font->loadFromFile("font.ttf");
	//draw the scoreboard above the game
	this->score1 = new Score(*font, 64U);
	this->score1->setPosition(window->getSize().x/4, 0);
	this->score2 = new Score(*font, 64U);
	this->score2->setPosition(window->getSize().x/2 + window->getSize().x/4, 0);
	//draw the paddles, P1 = left player, P2 = right player
	this->player1 = new paddle_player(0);
	this->player1->setPosition(10, window->getSize().y /2 + this->player1->getGlobalBounds().height/4);
	this->player2 = new paddle_player(1);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width - 10, window->getSize().y/2 + this->player2->getGlobalBounds().height / 4);
	//draw blocks
	//block *blockObject = new block[1];
	this->blockObject = new block(window);
	this->blockObject->setOrigin(25, 25);
	this->blockObject->blockReset(0);
	this->blockObject1 = new block(window);
	this->blockObject1->setOrigin(25, 25);
	this->blockObject1->blockReset(1);
	this->blockObject2 = new block(window);
	this->blockObject2->setOrigin(25, 25);
	this->blockObject2->blockReset(2);

	//draw ball in the middle
	this->ballObject = new ball(window, this->score1, this->score2, this->player1, this->player2, this->blockObject, this->blockObject1, this->blockObject2);
	this->ballObject ->setPosition(window->getSize().x/2, window->getSize().y/2);



}
//update objects
void main_game::Update(sf::RenderWindow* window){

	this->player1->Update();
	this->player2->Update();
	this->blockObject->Update();
	this->blockObject1->Update();
	this->blockObject2->Update();
	this->score1->Update();
	this->score2->Update();
	this->ballObject->Update(window);

	//escape sends back to main menu, resets score
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
		coreState.SetState(new menu());
	}
	
}
//draw objects
void main_game::Render(sf::RenderWindow* window){
	window->draw(*this->score1);
	window->draw(*this->score2);
	window->draw(*this->blockObject);
	window->draw(*this->blockObject1);
	window->draw(*this->blockObject2);
	window->draw(*this->ballObject);
	window->draw(*this->player1);
	window->draw(*this->player2);
	

} 
//cleanup
void main_game::Destroy(sf::RenderWindow* window){
	delete this->player1;
	delete this->player2;
	delete this->ballObject;
	delete this->score1;
	delete this->score2;
	delete this->blockObject;
	delete this->blockObject1;
	delete this->blockObject2;
}

