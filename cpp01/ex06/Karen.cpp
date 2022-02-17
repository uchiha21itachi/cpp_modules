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
    int             num = -1;

    str[0] = "DEBUG";
    str[1] = "INFO";
    str[2] = "WARNING";
    str[3] = "ERROR";
    for(int i = 0; i < 4; i++)
    {
        if (!(str[i].compare(level)))
        {
            num = i;
        }
    }
    switch (num)
    {
        case 0:         (this->*_stages[0])();
        case 1:         (this->*_stages[1])();
        case 2:         (this->*_stages[2])();
        case 3:         (this->*_stages[3])();
                        break;
        default:        std::cout <<"[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

Karen::~Karen(void)
{
}

void    Karen::_debug(void)
{
    std::cout <<"       [DEBUG]      \n";   
    std::cout << "I love having extra bacon for my" <<
    "7XL-double-cheese-triple-pickle-specialketchup burger\n. I really do!\n" <<
    std::endl;

}

void    Karen::_info(void)
{
    std::cout <<"       [INFO]      \n";   
    std::cout << "I cannot believe adding extra bacon costs more money.\n" <<
    "You didn't put enough bacon in my burger!\n" <<
    "If you did, I wouldn't be asking for more!\n" <<
    std::endl;
}

void    Karen::_warning(void)
{
    std::cout <<"       [WARNING]      \n";   
    std::cout << "I think I deserve to have some extra bacon for free.\n" << 
    "I've been coming for years whereas you started working here since last month.\n" <<
    std::endl;
}

void    Karen::_error(void)
{
    std::cout <<"       [ERROR]      \n";   
    std::cout <<"This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}