#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "Hello A new animal " << this->type << " is naturally born" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Hello an animal " << this->type << " has died" << std::endl;
}

Cat & Cat::operator=(const Cat &other)
{
    Animal::operator=(other);
    return *this;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Hello an animal " << this->type << " is born from another Cat" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Animal says Meow Meow" << std::endl;
}