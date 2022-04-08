#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
    std::cout << "(Cure default):\t\t\t A new Cure is created." << std::endl;
}


Cure::~Cure()
{
    std::cout << "(Cure destructor):\t\t Cure destroyed." << std::endl;
}

Cure::Cure(const Cure & other): AMateria(other)
{
    std::cout << "(Cure copy):\t\t A new Cure is created." << std::endl;
}

Cure & Cure::operator=(const Cure &other)
{
    std::cout << "(Cure operator=):\t\t A new Cure is created." << std::endl;
    AMateria::operator=(other);
    return *this;
}

AMateria * Cure::clone() const
{
    AMateria *temp = new Cure;
    return (temp);
}

void   Cure::use(ICharacter & target)
{
    std::cout << "\n" << this->getType() << " * Heals " << target.getName() << "'s wounds  *\n" << std::endl;
}
