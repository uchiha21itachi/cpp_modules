#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string     _name;

    public:
        void    announce(void) const;
        void    set_name(std::string str);
        Zombie(std::string name);
        Zombie(void);
       ~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif