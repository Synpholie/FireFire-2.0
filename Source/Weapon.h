#pragma once
#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Weapon : public Entity
{
public:
	enum Type
	{
		PlayerBullet,
		EnemyBulletZ,
		EnemyBulletD,
		PlayerBomb,
		TypeCount
	};


public:
	Weapon(Type type, const TextureHolder& textures);

	virtual unsigned int getCategory() const;
	virtual sf::FloatRect getBoundingRect() const;
	float getMaxSpeed() const;
	int getDamage() const;
	// Call setOrigin() with the center of the object
	void			centerOrigin(sf::Sprite& sprite);


private:
	virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	Type mType;
	sf::Sprite mSprite;
	sf::Vector2f mTargetDirection;
};