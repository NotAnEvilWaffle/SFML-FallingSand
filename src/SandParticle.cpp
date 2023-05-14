#include "SandParticle.h"
#include <iostream>



SandParticle::SandParticle(sf::Vector2i position) : Particle(sf::Color::Yellow, position, ParticleType::Sand)
{
    
}

SandParticle::~SandParticle()
{
}

void SandParticle::UpdatePhysics(std::vector<std::vector<Particle*>> &grid)
{
    //Particle::UpdatePhysics(grid);
    /*
        Sand Rules:
        1. Empty Space Below: Move Down
        2. Else, Empty Space Down and Left: Move Down and Left
        3. Else, Empty Space Down and Right: Move Down and Right   
    */

    int oldX = position.x;
    int oldY = position.y;

    if (grid[oldX][oldY+1] == nullptr && oldY+1 < grid[0].size())
    {
        grid[oldX][oldY+1] = this;
        grid[oldX][oldY] = nullptr;

        position.y++;
        rect.setPosition(sf::Vector2f(this->position * particleSize));
    }

    else if (grid[oldX-1][oldY+1] == nullptr && grid[oldX+1][oldY+1] == nullptr)
    {
        bool direction = rand() % 2;
        if (direction == 0) {
            
            grid[oldX][oldY] = nullptr;
            grid[oldX - 1][oldY + 1] = this;

            position.x--;
            position.y++;
            
        }
        else if (direction == 1) {
            grid[oldX][oldY] = nullptr;
            grid[oldX + 1][oldY + 1] = this;

            position.x++;
            position.y++;
        }

        rect.setPosition(sf::Vector2f(this->position * particleSize));
    }

    else if (grid[oldX - 1][oldY + 1] == nullptr) {
        grid[oldX][oldY] = nullptr;
        grid[oldX - 1][oldY + 1] = this;

        position.x--;
        position.y++;
        rect.setPosition(sf::Vector2f(this->position * particleSize));
    }

    else if (grid[oldX + 1][oldY + 1] == nullptr) {
        grid[oldX][oldY] = nullptr;
        grid[oldX + 1][oldY + 1] = this;

        position.x++;
        position.y++;
        rect.setPosition(sf::Vector2f(this->position * particleSize));
    }
}
