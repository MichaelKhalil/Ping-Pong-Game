#include "score.h"


Score::Score(sf::Font &font, unsigned int size) : sf::Text("score: 0", font, size){
	this->value = 0;
}
void Score::IncrementScore(){
	this->value+= 1;
}

void Score::Update(){
	this->setString(std::to_string(this->value));
}