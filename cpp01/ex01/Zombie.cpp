#include "Zombie.hpp"

Zombie::Zombie (void)
{
    
}

Zombie::Zombie (std::string name) 
{
    this->_name = name;
}

void    Zombie::announce(void) const
{
    std::cout << this->_name 
    << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string str)
{
    this->_name = str;
}

Zombie::~Zombie()
{
    std::cout << this->_name 
    << " Zzzzz aaahhhhhggghhhh I am dead......" << std::endl; 
}
