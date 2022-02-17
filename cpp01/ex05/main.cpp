#include "Karen.hpp"

int main(void)
{

    Karen one;

    std::cout << "\n" << std::endl;
    one.complain("info");
    std::cout << "\n" << std::endl;
    one.complain("warning");
    std::cout << "\n" << std::endl;
    one.complain("error");
    std::cout << "\n" << std::endl;
    one.complain("debug");
    std::cout << "\n" << std::endl;
    one.complain("blablabla");
    return (0);
}