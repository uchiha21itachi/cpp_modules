#include "Dog.hpp"

Dog::Dog(void): Animal("dog")
{
    std::cout << "(Dog default):\t\t Hello fellow humans - type -" << this->type << " is born naturally" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "(Dog destructor):\t Hello an animal " << this->type << " has died" << std::endl;
}

Dog & Dog::operator=(const Dog &other)
{
    std::cout << "(Dog operator=):\t\t A Dog have copied attributes from another Animal" << std::endl;
    Animal::operator=(other);
    return *this;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "(Dog copy):\t Hello an animal " << this->type << " is born from another dog" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Animal says Bow Bow" << std::endl;
}