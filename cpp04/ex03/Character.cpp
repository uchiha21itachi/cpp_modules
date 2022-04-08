#include "Character.hpp"

Character::Character(): _name("defaultChar")
{
    std::cout << "(Character Default):\t\t Character Created." << std::endl;
    for (int i = 0; i < 4; i++)
    {   
        this->_mat[i] = 0;
    }
}

Character::Character(std::string const str): _name(str)
{
    std::cout << "(Character Name):\t\t Character Created." << std::endl;
    for (int i = 0; i < 4; i++)
    {   
        this->_mat[i] = 0;
    }
}

Character::~Character()
{
    for (int i=0; i < 4; i++)
    {
        if (this->_mat[i] != 0)
            delete this->_mat[i];
    }
    std::cout << "(Character destructor):\t\t Character destroyed." << std::endl;
}

Character::Character(const Character & other)
{
    *this = other;
    std::cout << "(Character copy):\t\t A new Character is created." << std::endl;
}

Character & Character::operator=(const Character &other)
{
    std::cout << "(Character operator=):\t\t A new Character is created." << std::endl;
    this->_name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (this->_mat[i] != 0)
            delete this->_mat[i];
        if (other._mat[i] == 0)
            this->_mat[i] = 0;
        else
            this->_mat[i] = other._mat[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (m == 0)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->_mat[i] == 0)
        {
            this->_mat[i] = m;
            std::cout << "\nA Materia of type " << this->_mat[i]->getType() << " have been equiped successfully by - " << this->_name << " Character\n" << std::endl;
            return;
        }
    }
    std::cout << this->_name << " Character inventory is full. Cannot add another Material" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << this->_name << " Cannot unequip a material. Please check the input usage[0 - 3] " << std::endl;
        return ;
    }
    if (this->_mat[idx] == 0)
    {
        std::cout << this->_name << " does not have any material in this position" << std::endl;
        return ;
    }
    this->_mat[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << this->_name << " Cannot unequip a material. Please check the input usage[0 - 3] " << std::endl;
        return ;
    }
    if (this->_mat[idx] == 0)
        return;
    this->_mat[idx]->use(target);
}