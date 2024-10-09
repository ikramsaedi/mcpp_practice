#include <iostream>
#include <vector>
#include <mcpp/mcpp.h>
#include "Env.h"

int main()
{
    Environment maze;
    maze.readEnv();
    std::cout << "Hello World!" << std::endl;
    std::cout << std::endl;

    std::string temp;
    std::cin >> temp;

    int x;
    int y;
    int z;

    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    mcpp::MinecraftConnection mc;
    mcpp::Coordinate coord = mc.getPlayerPosition();

    std::cout
        << coord << std::endl;

    maze.build(coord, mc);
    mc.setBlock(coord, mcpp::Blocks::BRICKS);

    mc.postToChat("Hello Minecraft!");
    mc.doCommand("time set day");
    mc.doCommand("weather clear");

    return 0;
}