#include <vector>
#include <mcpp/mcpp.h>

#define WALL 'x'
#define AIR_BLOCK '.'

class Environment
{
public:
    int height;
    int width;

    std::vector<std::vector<char>> env;

    Environment();

    // read height and width and the structure from std::cin
    void readEnv();
    void build(mcpp::Coordinate &, mcpp::MinecraftConnection &);
    void print();
};