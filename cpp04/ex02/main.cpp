#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{

    {   
        const AAnimal* i = new Cat();
        const AAnimal* k = new Dog();
        // const AAnimal* j = new AAnimal();

        std::cout << "\n\n\n" << std::endl;
        // j->makeSound();
        i->makeSound();
        k->makeSound();
        std::cout << "\n\n\n" << std::endl;
        
        // delete j;
        delete i;
        delete k;
    }
    return 0;
}
