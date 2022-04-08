#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "Hello A new wrongAnimal " << this->type << " is naturally born" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "Hello a wrongAnimal " << this->type << " has died" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &other)
{
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "Hello a WrongAnimal " << this->type << " is born from another WrongCat" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongAnimal says Meow Meow" << std::endl;
}