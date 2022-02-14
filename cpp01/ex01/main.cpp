#include "Zombie.hpp"


int main(void)
{
    int n;

    std::cout << "Welcome to Zombieland" << std::endl;
    std::cout << "So, tell me how many zombies do you need for your adventure..!!!???" << std::endl;
    std::cout << "Just make sure you put more than a ZEROOO lol\n" << std::endl;
    std::cin >> n;

    Zombie *zombie_one = zombieHorde(n, "brand");
    for (int i = 0; i < n; i++)
    {
        zombie_one[i].announce();
    }
    delete [] zombie_one;
    return (0);   
}