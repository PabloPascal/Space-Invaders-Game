#include "Game.h"
#include <iostream>

sf::Time TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game() : mWindow(sf::VideoMode(640, 480), "Game", sf::Style::Close), mPlayer(), mTexture()
{
	mIsMovingUp = false;
	mIsMovingDown = false;
	mIsMovingLeft = false;
	mIsMovingRight = false;

	if (!mTexture.loadFromFile("Media/textures/Eagle.png")) {
		std::cout << "can't open the file";
	}

	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
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
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp) {
		movement.y -= 100.f;
	}
	if (mIsMovingDown) {
		movement.y += 100.f;
	}
	if (mIsMovingLeft) {
		movement.x -= 100.f;
	}
	if (mIsMovingRight) {
		movement.x += 100.f;
	}

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
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
