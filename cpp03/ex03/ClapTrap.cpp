#include "ClapTrap.hpp"

/* Constructors Canonical Form  */

ClapTrap::ClapTrap (void): _name("NoName"), 
_hit_point(10),
_energy_points(10),
_attack_damage(0)
{
     std::cout << "(Default ClapTrap)\tA new ClapTrap called - " <<
    this->_name << " is hereeee !!!!!!!" << std::endl;
}

ClapTrap::~ClapTrap (void)
{
  std::cout << "(Destructor ClapTrap)\tDestroyed a ClapTrap - " << this->_name <<
    " Faddiinnnnnnnggggg aaagghhhghaha!!!!!!" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap & b)
{
    *this = b;
    std::cout << "(Copy ClapTrap)\t\tBehooollld.... New ClapTrap called" << 
    this->_name << " has been borned from another ClapTrap"<< std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap & b)
{
    this->_name = b._name;
    this->_hit_point = b._hit_point;
    this->_energy_points = b._energy_points;
    this->_attack_damage = b._attack_damage;
     std::cout << "(Copy=ClapTrap)\t All the attributes are infused in ClapTrap " << this->_name << 
    " from another ClapTrap..!!" << std::endl;
    return (*this);
}

/*
    End of Canonical Form Constructors
    Other Constructors
*/

ClapTrap::ClapTrap (std::string str): _name(str), 
_hit_point(10),
_energy_points(10),
_attack_damage(0)
{
    std::cout << "(Name ClapTrap)\t A new Named ClapTrap called - " << this->_name <<
    " Is hereee ....!!!" <<  std::endl;}

/* Member Functions */

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_point <= 0)
    {
        std::cout << "(Attack Clap)\t ClapTrap " << this->_name << " Cannot attack. No HP left " << std::endl;
        return;
    }
    if (this->_energy_points > 0)
    {
        this->_energy_points--;
        std::cout << "(Attack Clap)\t ClapTrap " << this->_name << " Attacked - " << target <<
        " causing " << this->_attack_damage << " Points of damage !!\n" << std::endl;  
    }
    else
    {
        std::cout << "(Attack Clap)\t ClapTrap " << this->_name << " Wants to attack " << this << std::endl;
        std::cout << "Cannot attack No EP...\n\n" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int     new_hp;

    if (this->_hit_point <= 0)
    {
        std::cout << "ClapTrap " << this->_name <<
        " Cannot take damage. Condition beyond hope... DEAD(0HP)\n" <<
        std::endl;
        return;
    }
    new_hp = this->_hit_point - amount;
 
    std::cout << "ClapTrap " << this->_name <<
    " took damage of " << amount << " Hit points" << std::endl;
    if (new_hp <= 0)
    {
        this->_hit_point = 0;
        std::cout << "ClapTrap " << this->_name <<
        " is beyond help... DEAD. " << this->_hit_point <<
        " Hit points\n" << std::endl;
    }
    else
    {
        this->_hit_point = new_hp;
        std::cout << "ClapTrap " << this->_name <<
        " HP after taking hit went - " << this->_hit_point <<
        " Hit points. Gotta be carefull now ...!!!!\n" << std::endl;   
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " Wants to be repaired for " << amount << " hit points" << std::endl;
    if (this->_hit_point <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " Cannot repair itself. Its too late..... ALREADY DEAD " <<
        this->_hit_point << " Hit points.\n" << std::endl;
        return; 
    }
    if (this->_energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " Cannot repair. NO ENERGY LEFT.\n" << std::endl;
        return;
    }
    if (amount <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " heal amount is really low. Cannot heal\n" << std::endl;
        return;
    }
    this->_energy_points--;
    this->_hit_point += amount;
    std::cout << "ClapTrap " << this->_name <<
    " Repaired. This Claptrap have " << this->_hit_point <<
    " hit points now....\n" << std::endl;   
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->_attack_damage);
}
