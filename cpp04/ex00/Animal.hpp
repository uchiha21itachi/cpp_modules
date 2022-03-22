#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

    public:

        Animal(void);
        virtual ~Animal(void);
        Animal(const Animal &other);
        Animal & operator=(const Animal &other);

        Animal(const std::string &str);

        std::string getType(void) const;

        virtual void makeSound(void) const;



    protected:

        std::string     type;

};


#endif