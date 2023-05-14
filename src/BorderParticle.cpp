#include "BorderParticle.h"
#include <iostream>

BorderParticle::BorderParticle(sf::Vector2i position) : Particle(sf::Color::Black, position, ParticleType::Border)
{
    
}

BorderParticle::~BorderParticle()
{
}

void BorderParticle::UpdatePhysics(std::vector<std::vector<Particle*>> &grid)
{
    
}
