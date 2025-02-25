// SfmlTemplate.cpp : définit le point d'entrée pour l'application console.
//
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <vector>
#include "Managers\GameManager.h"
#include "Managers\PollEventManager.h"
#include "Tools\Defines.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Projet vide" /*, sf::Style::Fullscreen*/);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	srand(time(NULL));

	PollEventManager::Instance()->init(window);
	GameManager::Instance()->init(window);


	//window.setMouseCursorVisible(false);

	while (window.isOpen())
	{
		//sf::Event event;
		//while (window.pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		//		window.close();

		//}
		GameManager::Instance()->update();
		PollEventManager::Instance()->update();
		
		window.clear();

		GameManager::Instance()->display();

		window.display();
	}

	return 0;
}