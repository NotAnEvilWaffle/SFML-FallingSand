#pragma once
#include "Particle.h"

// The default particle

class SandParticle : public Particle
{
private:
    
public:
    SandParticle(sf::Vector2i position);
    ~SandParticle();

    void UpdatePhysics(std::vector<std::vector<Particle*>> &grid) override;
};


