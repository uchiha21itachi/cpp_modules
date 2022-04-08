#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "(Cat default):\t\t Hello fellow humans - type -" << this->type << " with brain is born naturally" << std::endl;
}

Cat::~Cat(void)
{
    delete this->brain;
    std::cout << "(Cat destructor):\t Hello an animal " << this->type << " has died" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "(Cat copy):\t Hello an animal " << this->type << " is born from another Cat" << std::endl;
    this->brain = 0;
    *this = other;
}

Cat & Cat::operator=(const Cat &other)
{
    if (this == &other)
        return *this;
    if (this->brain != 0)
        delete this->brain;
    this->brain = new Brain(*other.getBrain());    
    std::cout << "(Cat operator=):\t\t A Cat have copied attributes from another Animal" << std::endl;
    Animal::operator=(other);
    return *this;
}


Brain * Cat::getBrain(void) const
{
    return (this->brain);
}

void Cat::makeSound(void) const
{
    std::cout << "Animal says Meow Meow" << std::endl;
}