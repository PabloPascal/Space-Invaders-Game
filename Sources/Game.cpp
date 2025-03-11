#include "../Headers/Game.h"
#include <iostream>

sf::Time TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game() : mWindow(sf::VideoMode(640, 480), "Game", sf::Style::Close), mPlayer(), 
mWorld(mWindow)
{
	mIsMovingUp = false;
	mIsMovingDown = false;
	mIsMovingLeft = false;
	mIsMovingRight = false;


}


void Game::run() {

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen()) {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}


void Game::processEvents() {
	sf::Event event;

	while (mWindow.pollEvent(event)) {

		switch (event.type) {
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}


void Game::update(sf::Time deltaTime)
{
	mWorld.update(deltaTime);
}

void Game::render() {
	mWindow.clear();
	mWorld.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::W) {
		mIsMovingUp = isPressed;
	}
	else if (key == sf::Keyboard::S) {
		mIsMovingDown = isPressed;
	}
	else if (key == sf::Keyboard::A) {
		mIsMovingLeft = isPressed;
	}
	else if (key == sf::Keyboard::D) {
		mIsMovingRight = isPressed;
	}
}
