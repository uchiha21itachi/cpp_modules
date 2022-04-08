#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "(MateriaSource default):\t MateriaSource Created." << std::endl;
    for (int i = 0; i < 4 ; i++)
    {
        this->_source[i] = 0;
    }
}


MateriaSource::~MateriaSource()
{
    for (int i=0; i < 4; i++)
    {
        if (this->_source[i] != 0)
            delete this->_source[i];
    }
    std::cout << "(MateriaSource destructor):\t MateriaSource destroyed." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource & other)
{
    *this = other;
    std::cout << "(MateriaSource copy):\t\t A new MateriaSource is created." << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "(MateriaSource operator=):\t\t A new MateriaSource is created." << std::endl;
    for (int i = 0; i < 4 ; i++)
    {
        if (this->_source[i] != 0)
            delete  this->_source[i];
        if (other._source[i] == 0)
            this->_source[i] = 0;
        else
            this->_source[i] = other._source[i]->clone();
    }
    return *this;
}


void MateriaSource::learnMateria(AMateria* other)
 {

    for(int i = 0; i < 4; i++)
	{
		if (this->_source[i] == 0)
		{
			this->_source[i] = other;
			return ;
		}
	}
 }

AMateria* MateriaSource::createMateria(std::string const & type)
{
    AMateria * temp;

    for (int i = 0; i < 4; i++)
    {
        if (this->_source[i] != 0 && this->_source[i]->getType().compare(type) == 0)
        {
            temp = this->_source[i]->clone();
            return (temp);
        }
    }
    return (0);
}