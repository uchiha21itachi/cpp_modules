#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap a, b("RAVENN"), c(b), d("TRYNDAMEREE");
    ClapTrap clap("Sonna");
    FragTrap frag("FRANKKYYYY");
    a = d;
    
    std::cout << "\n\n\n" << std::endl;
    std::cout << "---------------Game starts here-----------------\n" << std::endl;
    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(30);
    a.attack(clap.getName());
    
    std::cout <<"\n\n\n testing FragTrap now....\n" << std::endl;
    
    //FragTrap attack and interact woth ClapTrap obj;
    frag.attack(clap.getName());
    clap.takeDamage(frag.getAttackDamage());
    frag.highFivesGuys();

    std::cout << "--------------------end-------------------------\n" << std::endl;
    return (0);
}