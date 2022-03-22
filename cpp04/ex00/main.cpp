#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n\n" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "\n\n" << std::endl;
    delete meta;
    delete i;
    delete j;

    std::cout << "\n\n" << std::endl;
    const WrongAnimal* po = new WrongAnimal();
    const WrongAnimal* lo = new WrongCat();
    std::cout << "\n\n" << std::endl;
    std::cout << po->getType() << " " << std::endl;
    std::cout << lo->getType() << " " << std::endl;
    po->makeSound();
    lo->makeSound();
    std::cout << "\n\n" << std::endl;
    delete po;
    delete lo;
    return (0);
}