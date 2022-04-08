#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

    public:

        Cat(void);
        ~Cat(void);
        Cat(const Cat &other);
        Cat & operator=(const Cat &other);

        virtual void makeSound(void) const;

        Brain * getBrain(void) const;

    private:
        Brain *brain;
};


#endif