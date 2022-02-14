#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>

class Weapon {
    public:
        Weapon(std::string type);
        ~Weapon(void);
        const std::string & getType() const;
        void    setType(const std::string & newtype);

    private:
        std::string  _type;

};

#endif