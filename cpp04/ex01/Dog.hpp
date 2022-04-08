#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

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