#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zombie_new(name);
    zombie_new.announce();
}