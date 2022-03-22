#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
    std::cout << "Hello fellow humans a new WrongAnimal of type -" << this->type << " is born naturally" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "An WrongAnimal of type " <<  this->type
    << " is perishing into nothingness..Thanks a lot humans!!!" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other)
{
    this->type = other.type;
    std::cout << "= operator WrongAnimal called" << std::endl;
    return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "copy constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &str)
{
    this->type = str;
    std::cout << "A new WrongAnimal of type -" << this->type << " is born" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void    WrongAnimal::makeSound(void)const
{
    std::cout << "Creature says whaattt>>?" << std::endl;
}