#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <deque>


template <typename T>
void	easyfind(T const & container, int const to_find)
{
    try
    {
        typename T::const_iterator n = std::find(container.begin(), container.end(), to_find);
        if (n != container.end()) 
        {
            std::cout << "\e[0;33m Found " << to_find << "in the container " << std::endl; 
        }
        else
        {
			std::cerr << "The container does not contain " << to_find << std::endl;
        }
        
    }
    catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}   

#endif