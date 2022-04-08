#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
        ~MateriaSource();
        MateriaSource(const MateriaSource & other);
        MateriaSource & operator=(const MateriaSource & other);

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);

    private:
        AMateria * _source[4];

};


#endif