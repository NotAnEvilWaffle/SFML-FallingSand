#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "SandParticle.h"
#include "BorderParticle.h"

class World : public sf::Drawable
{
private:
    std::vector<std::vector<Particle*>> grid;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int width, height;
public:
    World(int width, int height, int particleSize = 1);
    ~World();

    void Update();
    void AddParticle(int x, int y);
};


