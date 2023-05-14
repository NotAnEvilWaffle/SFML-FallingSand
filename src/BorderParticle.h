#pragma once
#include "Particle.h"

// Border Particle was meant specifically to outline the map with to avoid bounds checking
class BorderParticle : public Particle
{
private:
    
public:
    BorderParticle(sf::Vector2i position);
    ~BorderParticle();

    void UpdatePhysics(std::vector<std::vector<Particle*>> &grid) override;
};