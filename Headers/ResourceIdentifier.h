#ifndef RESOURCE_IDENTIFIER_H
#define RESOURCE_IDENTIFIER_H

namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Eagle,
		Raptor,
		Desert,
	};
}


template <typename Resource, typename Identifier>
class ResourceHolder;

using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;


#endif