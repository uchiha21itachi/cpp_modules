#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap a, b("RAVENN"), c(b), d("TRYNDAMEREE");
    ClapTrap crazy("Sonna");
    a = d;
    
    std::cout << "\n\n\n" << std::endl;
    std::cout << "---------------Game starts here-----------------\n" << std::endl;
    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(30);
    a.attack(crazy.getName());

    std::cout << "--------------------end-------------------------\n" << std::endl;
    return (0);
}