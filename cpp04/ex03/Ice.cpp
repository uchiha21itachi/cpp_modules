#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    std::cout << "(ice default):\t\t\t A new ice is created." << std::endl;

}

Ice::~Ice()
{
    std::cout << "(Ice destructor):\t\t Ice destroyed." << std::endl;
}

Ice::Ice(const Ice & other): AMateria(other)
{
    std::cout << "(Ice copy):\t\t A new Ice is created." << std::endl;
}

Ice & Ice::operator=(const Ice &other)
{
    std::cout << "(Ice operator=):\t\t A new Ice is created." << std::endl;
    AMateria::operator=(other);   
    return *this;
}

AMateria * Ice::clone() const
{
    AMateria *temp = new Ice;
    return (temp);
}

void   Ice::use(ICharacter & target)
{
    std::cout << "\n" << this->getType() << "* shoots an ice bolt at " << target.getName() << " bam bam *\n" << std::endl;
}

