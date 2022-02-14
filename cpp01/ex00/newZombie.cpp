#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie  *zombie_new;

    zombie_new = new Zombie(name);
    return (zombie_new);
}
