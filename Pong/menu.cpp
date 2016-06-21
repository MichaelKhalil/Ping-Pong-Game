#include <iostream>
#include "menu.h"

void menu::Initialize(sf::RenderWindow* window){
	this->selected = 0;
	this->font = new sf::Font();
	this->font->loadFromFile("font.ttf");
	this->title = new sf::Text("ping", *this->font, 200U);
	this->title->setOrigin(this->title->getGlobalBounds().width/2, this->title->getGlobalBounds().height/2);
	this->title->setPosition(window->getSize().x/2, window->getSize().y/8);

	this->play = new sf::Text("play", *this->font, 128U);
	this->play->setOrigin(this->play->getGlobalBounds().width/2, this->play->getGlobalBounds().height/2);
	this->play->setPosition(window->getSize().x/2, window->getSize().y/2);

	this->quit = new sf::Text("quit", *this->font, 128U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width/2, this->quit->getGlobalBounds().height/2);
	this->quit->setPosition(window->getSize().x/2, (window->getSize().y/2)+(window->getSize().y/4));

	std::cout << "init\n";

}
void menu::Update(sf::RenderWindow* window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey){
		this->selected -= 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey){
		this->selected += 1;
	}
	if(this->selected > 1)
		this->selected = 0;
	if(this->selected < 0)
		this->selected = 1;

	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}
void menu::Render(sf::RenderWindow* window){

	this->play->setColor(sf::Color::White);
	this->quit->setColor(sf::Color::White);
	switch(this->selected){

	case 0:
		this->play->setColor(sf::Color::Green);
		break;
	case 1:
		this->quit->setColor(sf::Color::Green);

	}
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);
}
void menu::Destroy(sf::RenderWindow* window){
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->quit;
	std::cout << "des\n";
}
