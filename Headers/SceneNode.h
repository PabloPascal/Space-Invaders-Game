#ifndef SCENE_NODE
#define SCENE_NODE

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <cassert>

class SceneNode: sf::Transformable, sf::Drawable, sf::NonCopyable
{
public:
	
	using S_ptr = std::unique_ptr<SceneNode>;

public:

	SceneNode();

	void attachChildren(S_ptr child);
	S_ptr detachChildren(const SceneNode& node);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<S_ptr> mChildren; 
	SceneNode* mParent;
};


#endif // !SCENE_NODE
