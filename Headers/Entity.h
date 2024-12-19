#ifndef ENTITY_H
#define ENTITY_H
#include "SceneNode.h"

#include <SFML/Graphics.hpp>

class Entity : public SceneNode
{

	sf::Vector2f mVelocity;
public:

	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;

};


#endif // !ENTITY_H
