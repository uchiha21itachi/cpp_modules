#include <string>
#include <iostream>

int main()
{
    std::string    someString;

    someString = "HI THIS IS BRAIN";
    
    std::string     *stringPTR;
    std::string     &stringREF = someString;
    stringPTR = &someString;

    std::cout << "• The memory address of the string variable - \t[" << &someString << "]" << std::endl;
    std::cout << "• The memory address held by stringPTR - \t[" << stringPTR << "]" << std::endl;
    std::cout << "• The memory address held by stringREF - \t[" << &stringREF << "]" << std::endl;
    std::cout << "\n\n" << std::endl;
    std::cout << "• The value of the string variable - \t [" << someString << "]" << std::endl;
    std::cout << "• The value pointed to by stringPTR - \t [" << *stringPTR << "]" << std::endl;
    std::cout << "• The value pointed to by stringREF - \t [" << stringREF << "]" << std::endl;


    return (0);
}