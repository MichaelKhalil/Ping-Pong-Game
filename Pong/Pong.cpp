

#include "game_state.h"
#include "menu.h"

game_state coreState; 


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ping Pong");

	coreState.SetWindow(&window);
	coreState.SetState(new menu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}


		coreState.Update();
		coreState.Render();

		window.display();
	}

	return 0;
}