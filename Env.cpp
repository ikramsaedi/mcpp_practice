#include "Env.h"

Environment::Environment()
{
    this->height = 0;
    this->width = 0;
}
// read height and width and the structure from std::cin
void Environment::readEnv()
{
    int height;
    int width;
    std::cin >> height;
    std::cin >> width;

    std::vector<std::vector<char>> env;

    // each charac
    for (int i = 0; i < height; i++)
    {
        std::vector<char> inner;
        for (int j = 0; j < width; j++)
        {
            char c;
            std::cin >> c;
            inner.push_back(c);
        }

        this->env.push_back(inner);
    }
}

void Environment::build(mcpp::Coordinate &start, mcpp::MinecraftConnection &mc)
{
    int h = 0;
    int w = 0;

    for (auto inner : env)
    {
        for (auto c : inner)
        {
            mcpp::Coordinate offsetcoord(start.x + h, start.y, start.z + w);
            std::cout << c;
            if (c == WALL)
            {
                mc.setBlock(offsetcoord, mcpp::Blocks::BRICKS);
            }
            else if (c == AIR_BLOCK)
            {
                mc.setBlock(offsetcoord, mcpp::Blocks::AIR);
            }
            w++;
        }
        std::cout << std::endl;
        h++;
        w = 0;
    }
}

void print();