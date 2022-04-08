#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <limits.h>

template <typename T>
void iter(T* tab, int size, void (*func)(const T&))
{
    for (int i = 0; i < size; i++)
        func(tab[i]);
}

template<typename T>
void	print(T const & a)
{
	std::cout << a << std::endl;
	return ;
}


#endif