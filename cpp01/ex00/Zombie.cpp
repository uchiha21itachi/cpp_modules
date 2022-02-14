#include "Zombie.hpp"

Zombie::Zombie (std::string name) 
{
    this->_name = name;
}

void    Zombie::announce(void) const
{
    std::cout << this->_name 
    << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name 
    << " Zzzzz aaahhhhhggghhhh I am dead......" << std::endl; 
}