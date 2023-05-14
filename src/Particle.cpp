#include "Particle.h"

int Particle::particleSize = 1;

Particle::Particle(sf::Color color, sf::Vector2i position, ParticleType type)
{
    this->type = type;
    this->position = position;
    rect = sf::RectangleShape(sf::Vector2f(particleSize, particleSize));
    rect.setFillColor(color);
    //rect.setSize({1,1});
    rect.setPosition(sf::Vector2f(this->position * particleSize));
    
}


Particle::~Particle()
{
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect);
}

void Particle::UpdatePhysics(std::vector<std::vector<Particle*>> &grid)
{
    if(updated)
    {
        updated = false;
        return;
    }

}

