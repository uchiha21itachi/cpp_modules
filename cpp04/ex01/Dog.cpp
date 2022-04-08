#include "Dog.hpp"

Dog::Dog(void): Animal("dog")
{
    this->brain = new Brain();
    std::cout << "(Dog default):\t\t Hello fellow humans - type -" << this->type << " with brain is born naturally" << std::endl;
}

Dog::~Dog(void)
{
    delete this->brain;
    std::cout << "(Dog destructor):\t Hello an animal " << this->type << " has died" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "(Dog copy):\t Hello an animal " << this->type << " with brain is born from another dog" << std::endl;
    this->brain = 0;
    *this = other;
}

Dog & Dog::operator=(const Dog &other)
{
    if (this == &other)
        return *this;
    if (this->brain != 0)
        delete this->brain;
    this->brain = new Brain(*other.getBrain());    
    std::cout << "(Dog operator=):\t\t A Dog have copied attributes from another Animal" << std::endl;
    Animal::operator=(other);
    return *this;
}


void Dog::makeSound(void) const
{
    std::cout << "Animal says Bow Bow" << std::endl;
}

Brain * Dog::getBrain(void) const
{
    return this->brain;
}