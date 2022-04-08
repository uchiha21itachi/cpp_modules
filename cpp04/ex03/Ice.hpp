#ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"


class Ice : public AMateria
{
    public:
        
        Ice(void);
        ~Ice(void);
        Ice(const Ice & other);
        Ice & operator=(const Ice &other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};


#endif