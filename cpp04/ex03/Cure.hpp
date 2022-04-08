#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"


class Cure : public AMateria
{
    public:
        
        Cure(void);
        ~Cure(void);
        Cure(const Cure & other);
        Cure & operator=(const Cure &other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};


#endif