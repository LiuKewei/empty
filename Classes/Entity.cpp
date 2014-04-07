#include "Entity.h"

Entity::Entity()
{
	m_sprite = NULL;
}
Entity::~Entity()
{

}

CCSprite* Entity::getSprite()
{
	return this->m_sprite;
}

void Entity::setSpriteAsNULL()
{
	this->m_sprite = NULL;
}

void Entity::bindSprite(CCSprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);
}