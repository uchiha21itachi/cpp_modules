#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

    public:

        Dog(void);
        virtual ~Dog(void);
        Dog(const Dog &other);
        Dog & operator=(const Dog &other);

        virtual void makeSound(void) const;

        Brain * getBrain(void) const;
    
    private:

        Brain *brain;
};


#endif