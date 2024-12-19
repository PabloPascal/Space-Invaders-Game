#ifndef RESOURCE_HOLDER_H
#define RESOURCE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder {
private:

	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

public:

	void load(Identifier id, const std::string& filename);

	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);

	Resource& get(Identifier id);

	const Resource& get(Identifier id) const;

};

#include "ResourceHolder.inl"
#endif // !RESOURCE_HOLDER_H
