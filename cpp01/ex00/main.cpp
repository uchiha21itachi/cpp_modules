#include "Zombie.hpp"

int main(void)
{
    Zombie  *a;

    randomChump("zed");
    a = newZombie("yash");
    a->announce();
    randomChump("zazuu");
    delete a;

    Zombie b("lulu");
	
	Zombie* one = newZombie("Viktor");
	one->announce();
	delete one;
	
	b.announce();
	randomChump("Brand");
    Zombie& two = b;
    two.announce();
	b.announce();
	return (0);
}