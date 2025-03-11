#ifndef WORLD_H
#define WORLD_H

#include "ResourceHolder.h"
#include "ResourceIdentifier.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Aircraft.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>


namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();


private:
	void loadTextures();
	void buildScene();


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
};

#endif // WORLD_H