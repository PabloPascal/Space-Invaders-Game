#include "../Headers/SceneNode.h"
#include "../Headers/FOREACH.h"


SceneNode::SceneNode() : mChildren(), mParent(nullptr)
{
}


void SceneNode::attachChildren(S_ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}


SceneNode::S_ptr SceneNode::detachChildren(const SceneNode& node) 
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](S_ptr& sp) { return sp.get() == &node; });
	assert(found != mChildren.end());

	S_ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	drawCurrent(target, states);
	drawChildren(target, states);

}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	FOREACH(const S_ptr & child, mChildren)
		child->draw(target, states);
}



void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	//do nothing by default
}


void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}


void SceneNode::updateCurrent(sf::Time)
{
	//do nothing by default
}

void SceneNode::updateChildren(sf::Time dt)
{
	FOREACH(S_ptr & child, mChildren)
		child->update(dt);
}


sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}



sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
		transform = node->getTransform() * transform;

	return transform;
}
