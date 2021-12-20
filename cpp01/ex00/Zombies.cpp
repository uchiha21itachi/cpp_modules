#include "Zombies.hpp"

Zombies::Zombies (std::string name) 
{
    this->_name = name;
}

std::string     Zombies::get_zombie_name() const
{
    return (this->_name);
}

void    Zombies::announce(void) const
{
    std::cout << this->get_zombie_name() << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombies::~Zombies()
{
    std::cout << this->get_zombie_name() << std::endl; 
}