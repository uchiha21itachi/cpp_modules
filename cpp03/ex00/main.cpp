#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Zorojuro"), b("breta");
    ClapTrap c(a), d;

    d = a;

    std::cout << "\n\n\n" << std::endl;
    std::cout << "---------------Game starts here-----------------\n" << std::endl;
    {
      a.attack(b.getName());
      b.takeDamage(a.getAttackDamage());
      b.takeDamage(8);
      b.beRepaired(1);
      b.takeDamage(4);
      b.beRepaired(1);
      b.attack(a.getName());
    }
  
  
    // a.beRepaired(1);
    // a.takeDamage(1);
    // a.beRepaired(1);
    // a.takeDamage(10);
    // a.beRepaired(10);

    // {
		// b.attack("Zorojuro");
		// b.attack("Zeus");
		// b.takeDamage(1);
		// b.takeDamage(8);
		// b.beRepaired(12);
    // }

    std::cout << "--------------------end-------------------------\n" << std::endl;
    return (0);
}