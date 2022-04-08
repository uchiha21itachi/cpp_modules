#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal {

    public:

        AAnimal(void);
        virtual ~AAnimal(void);
        AAnimal(const AAnimal &other);
        AAnimal & operator=(const AAnimal &other);

        AAnimal(const std::string &str);

        std::string getType(void) const;

        virtual void makeSound(void) const = 0;



    protected:

        std::string     type;

};


#endif