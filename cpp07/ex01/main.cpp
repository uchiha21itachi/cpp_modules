#include "iter.hpp"

int main() 
{ 
    int const tab[] = { 0, 1, 2, 3, 4 };
    iter( tab, 5, print );

    std::string  str[] = {"Yash", "Amine", "Adam", "Zoro", "Raven"};
    iter( str, 5, print );
    return 0;
} 