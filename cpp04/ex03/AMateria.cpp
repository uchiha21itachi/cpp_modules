#include "AMateria.hpp"

AMateria::AMateria():type("amateria")
{
    std::cout << "(AMateria default):\t\t A new AMateria is created." << std::endl;

}

AMateria::AMateria(std::string const & type): type(type)
{
    std::cout << "(AMateria string(type)):\t A new AMateria is created." << std::endl;

}

AMateria::~AMateria()
{
    std::cout << "(AMateria destructor):\t\t AMateria destroyed." << std::endl;
}

AMateria::AMateria(const AMateria & other)
{
    *this = other;
    std::cout << "(AMateria copy):\t\t A new AMateria is created." << std::endl;
}

AMateria & AMateria::operator=(const AMateria &other)
{
    std::cout << "(AMateria operator=):\t\t A new AMateria is created." << std::endl;
    this->type = other.getType();
    return *this;
}

std::string const & AMateria::getType() const 
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "(AMateria use) ametria attacks [ " << target.getName() << "] " << std::endl;
}