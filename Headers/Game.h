#ifndef GAME_H
#define GAME_H


#include "../Headers/ResourceHolder.h"


enum class ID{Airplane};


class Game {

public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	ResourceHolder<sf::Texture, ID> mTexture;


	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;


};

#endif 
