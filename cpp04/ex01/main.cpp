#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{

    {
        Brain *a = new Brain();

        std::cout << a->getIdea(2) << std::endl;
        std::cout << a->getIdea(10) << std::endl;
        std::cout << a->getIdea(99) << std::endl;
        std::cout << a->getIdea(-100) << std::endl;
        delete a;
    }
    {   
        const Animal* j = new Animal();
        const Animal* i = new Cat();

        std::cout << "\n\n\n" << std::endl;
        j->makeSound();
        i->makeSound();
        delete j;//should not create a leak
        delete i;
        std::cout << "\n\n\n" << std::endl;
    }
    {
        const Animal* animals[20];

		for (int i = 0; i < 10; i++)
			animals[i] = new Dog();
		for (int i = 10; i < 20; i++)
			animals[i] = new Cat();
		for (int i = 0; i < 20; i++)
			animals[i]->makeSound();
		for (int i = 0; i < 20; i++)
			delete animals[i];
		std::cout << std::endl;
    }

        Cat* cat = new Cat();
		Cat* cat2 = new Cat(*cat);

		std::cout << "Idea[0] of Cat A = " << cat->getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea[0] of Cat B = " << cat2->getBrain()->getIdea(0) << std::endl;
		std::cout << "Adress of Idea[0] of Cat A = " << &cat->getBrain()->getIdea(0) << std::endl;
		std::cout << "Adress of Idea[0] of Cat B = " << &cat2->getBrain()->getIdea(0) << std::endl;
		std::cout << "Setting Idea[0] of Cat A to 'Anonyme'" << std::endl;
		cat->getBrain()->setIdea(0, "Anonyme");
		std::cout << "Idea[0] of Cat A = " << cat->getBrain()->getIdea(0) << std::endl;
		std::cout << "Idea[0] of Cat B = " << cat2->getBrain()->getIdea(0) << std::endl;
		delete cat;
		delete cat2;
return 0;
}
