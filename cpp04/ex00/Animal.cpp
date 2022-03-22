#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
    std::cout << "Hello fellow humans a new animal of type -" << this->type << " is born naturally" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "An animal of type " <<  this->type
    << " is perishing into nothingness..Thanks a lot humans!!!" << std::endl;
}

Animal & Animal::operator=(const Animal &other)
{
    this->type = other.type;
    std::cout << "= operator animal called" << std::endl;
    return *this;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "copy constructor animal called" << std::endl;
}

Animal::Animal(const std::string &str)
{
    this->type = str;
    std::cout << "A new animal of type -" << this->type << " is born" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void    Animal::makeSound(void)const
{
    std::cout << "Creature says whaattt>>?" << std::endl;
}