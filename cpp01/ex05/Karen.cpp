#include "Karen.hpp"

Karen::Karen(void)
{
    this->_stages[0] = &Karen::_debug;
    this->_stages[1] = &Karen::_info;
    this->_stages[2] = &Karen::_warning;
    this->_stages[3] = &Karen::_error;
}

void Karen::complain( std::string level)  
{
    std::string     str[4];

    str[0] = "debug";
    str[1] = "info";
    str[2] = "warning";
    str[3] = "error";
    for(int i = 0; i < 4; i++)
    {
        if (!(str[i].compare(level)))
        {
            (this->*_stages[i])();
            return;
        }
    }
    std::cout <<"Level not found. This is one hella crazy Karen" << std::endl;
}

Karen::~Karen(void)
{

}

void    Karen::_debug(void)
{
    std::cout << "I love having extra bacon for my" <<
    "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<
    std::endl;

}

void    Karen::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money." <<
    "You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<
    std::endl;
}

void    Karen::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free." << 
    "I've been coming for years whereas you started working here since last month." <<
    std::endl;
}

void    Karen::_error(void)
{
    std::cout <<"This is unacceptable! I want to speak to the manager now." << std::endl;
}