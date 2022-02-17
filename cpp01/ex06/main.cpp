#include "Karen.hpp"

int main(int argc, char **argv)
{

    Karen one;

    if (argc != 2)
    {
        std::cout << "Usage ./karenFiter \"Message\"" << std::endl;
        return (1);
    }
    
    std::cout << "\n" << std::endl;
    one.complain(argv[1]);
    return (0);
}