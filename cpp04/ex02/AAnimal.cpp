#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("AAnimal")
{
    std::cout << "(AAnimal default):\t Hello fellow humans a new AAnimal of type -" << this->type << " is born naturally" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "(AAnimal Destructor):\t An AAnimal of type " <<  this->type
    << " is perishing into nothingness..Thanks a lot humans!!!" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal &other)
{
    this->type = other.type;
    std::cout << "(AAnimal operator=):\t\t An AAnimal have copied attributes from another AAnimal" << std::endl;
    return *this;
}

AAnimal::AAnimal(const AAnimal &other)
{
    *this = other;
    std::cout << "(AAnimal Copy):\t\t Hello fellow humans a new AAnimal of type -" <<
    this->type << "is born from another AAnimal" << std::endl;
}

AAnimal::AAnimal(const std::string &str)
{
    this->type = str;
    std::cout << "(AAnimal Name):\t\t A new AAnimal of type -" << this->type << " is born" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}
