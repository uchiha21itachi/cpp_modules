#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "(Cat default):\t\t Hello fellow humans - type -" << this->type << " is born naturally" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "(Cat destructor):\t Hello an animal " << this->type << " has died" << std::endl;
}

Cat & Cat::operator=(const Cat &other)
{
    std::cout << "(Cat operator=):\t\t A Cat have copied attributes from another Animal" << std::endl;
    Animal::operator=(other);
    return *this;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "(Cat copy):\t Hello an animal " << this->type << " is born from another Cat" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Animal says Meow Meow" << std::endl;
}