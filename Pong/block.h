#pragma once

#include "entity.h"

class block : public Entity{

public:
	block(sf::RenderWindow* window);
	void Update();
	void blockReset(int number);
	
private:
	
};

extern int blockCount;