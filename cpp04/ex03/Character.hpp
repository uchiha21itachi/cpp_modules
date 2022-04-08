#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character(std::string const str);
        ~Character();
        Character(const Character & other);
        Character & operator=(const Character & other);


        std::string const & getName() const;

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:

        Character(void);
        std::string     _name;
        AMateria *      _mat[4];

};  


#endif