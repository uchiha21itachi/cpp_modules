#ifndef ZOMBIES_CLASS_HPP
# define ZOMBIES_CLASS_HPP

#include <iostream>
#include <string>

class Zombies {

    std::string     _name;
    std::string     get_zombie_name(void) const;
    Zombies::~Zombies(void);

    public:
    void    announce(void) const;
    Zombies::Zombies(std::string name);
};

#endif