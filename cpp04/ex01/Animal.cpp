#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
    std::cout << "(Animal default):\t Hello fellow humans a new animal of type -" << this->type << " is born naturally" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "(Animal Destructor):\t An animal of type " <<  this->type
    << " is perishing into nothingness..Thanks a lot humans!!!" << std::endl;
}

Animal & Animal::operator=(const Animal &other)
{
    this->type = other.type;
    std::cout << "(Animal operator=):\t\t An animal have copied attributes from another animal" << std::endl;
    return *this;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "(Animal Copy):\t\t Hello fellow humans a new animal of type -" <<
    this->type << "is born from another animal" << std::endl;
}

Animal::Animal(const std::string &str)
{
    this->type = str;
    std::cout << "(Animal Name):\t\t A new animal of type -" << this->type << " is born" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void    Animal::makeSound(void)const
{
    std::cout << "Creature says whaattt>>?" << std::endl;
}