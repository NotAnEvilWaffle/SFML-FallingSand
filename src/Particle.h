#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

enum class ParticleType {Sand, Stone, Air, Border};

class Particle : sf::Drawable
{
private:
    


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    sf::Vector2i position;


    virtual void UpdatePhysics(std::vector<std::vector<Particle*>> &grid);

    bool updated = false;



public:
    static int particleSize;
    
    sf::RectangleShape rect;
    ParticleType type;
    Particle(sf::Color color, sf::Vector2i position, ParticleType type);
    Particle(int x, int y) : Particle()
    {
        this->position.x = x;
        this->position.y = y;
    };
    Particle()
    {
        type = ParticleType::Air;
    };
    ~Particle();

    friend class World;
};


