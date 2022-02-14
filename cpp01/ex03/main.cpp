#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon crusaderOne("Shinigami Scythe");
    Weapon crusaderTwo("Azurai Blade");
    {
        HumanA bob("Red Mantis", crusaderOne);
        bob.attack();
        crusaderOne.setType("Rhitta");
        bob.attack();
        {
            HumanB jim("Kakashi Hatake");
            jim.setWeapon(crusaderTwo);
            jim.attack();
            crusaderTwo.setType("Dorans Blade");
            jim.attack();
        }
    }   
    return (0);
}