#include "Dog.hpp"

Dog::Dog(void): Animal("dog")
{
    std::cout << "Hello A new animal " << this->type << " is naturally born" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Hello an animal " << this->type << " has died" << std::endl;
}

Dog & Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    return *this;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Hello an animal " << this->type << " is born from another dog" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Creature says Bow Bow" << std::endl;
}