#include "World.h"
#include <iostream>


World::World(int width, int height, int particleSize)
{
    this->width = width;
    this->height = height;

    for(int x = 0; x < width; x++)
    {
        grid.push_back(std::vector<Particle*>(height));

        for (int y = 0; y < height; y++)
        {
            // Make a border of solid particles 
            if (y == 0 || y == height || x == 0 || x == width)
            {
                grid[x][y] = new BorderParticle({x, y});
                continue;
            } 
            grid[x][y] = nullptr;
        }
    }

    
}

World::~World()
{
}

void World::AddParticle(int x, int y)
{
    grid[x][y] = new SandParticle({x, y});
}



void World::Update()
{

    // Traversing backwards is preferable for falling objects so particles moving faster don't stop when hitting on below it
    for (int x = width - 2; x >= 1; x--)
    {
        for (int y = height - 2; y >= 1; y--)
        {
            if (grid[x][y] == nullptr || grid[x][y]->updated == true) continue;
            grid[x][y]->updated = true;
            grid[x][y]->UpdatePhysics(grid);

        }
    }


    // This might be entirely redundant, but it sets the updated status back to false
    // Might be able to be done by each particle themselves to prevent another loop
    for (int x = width - 2; x >= 1; x--)
    {
        for (int y = height - 2; y >= 1; y--)
        {
            if (grid[x][y] == nullptr) continue;
            grid[x][y]->updated = false;

        }
    }



}



void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto &&row : grid)
    {
        for (auto &&particle : row)
        {
            if (particle == nullptr) continue;
            target.draw(*particle, states);
        }
        
    }
    
}