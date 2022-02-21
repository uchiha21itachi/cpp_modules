#include "Fixed.hpp"
#include <bitset>


int main( void ) 
{
    Fixed a(101);

	
	std::cout << "Fixed a = " << a << std::endl;
	std::cout << "[Preincrement]" << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "[Postincrement]" << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "Fixed a = " << a << std::endl;
	std::cout << "[Predecrement]" << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "[Postdecrement]" << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "[Multiplication]" << std::endl;
	std::cout << "Fixed const b(Fixed(5.05f) * Fixed(2)) = " << b << std::endl;
	std::cout << std::endl;

	Fixed const c(Fixed(80.88f) / Fixed(4.5f));
	std::cout << "[Division]" << std::endl;
	std::cout << "Fixed const c(Fixed(80.88f) / Fixed(4.5f)) = " << c << std::endl;
	std::cout << std::endl;

	std::cout << "[Substraction]" << std::endl;
	std::cout << "Fixed(8.09f) - Fixed(1.013f) = " << Fixed(8.09f) - Fixed(1.013f) << std::endl;
	std::cout << std::endl;

	std::cout << "[Addition]" << std::endl;
	std::cout << "Fixed(0.001f) + Fixed(-2.547f) = " << Fixed(0.001f) + Fixed(-2.547f) << std::endl;
	std::cout << std::endl;


	std::cout << "Max and min functions (static member one)" << std::endl;
	std::cout << "Fixed::max(a,b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "Max and min functions (overloaded function - non static - non member)" << std::endl;
	std::cout << "max(a,b) = " << max(a, b) << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << std::endl;


    std::cout << "[Comparison]" << std::endl;
	std::cout << "Fixed(0.001f) > Fixed(-2.547f) = " << (Fixed(0.001f) > Fixed(-2.547f)) << std::endl;
	std::cout << "Fixed(0.001f) < Fixed(-2.547f) = " << (Fixed(0.001f) < Fixed(-2.547f)) << std::endl;
	std::cout << "Fixed(0.001f) >= Fixed(0.001f) = " << (Fixed(0.001f) >= Fixed(0.001f)) << std::endl;
	std::cout << "Fixed(0.001f) <= Fixed(0.002f) = " << (Fixed(0.001f) <= Fixed(0.002f)) << std::endl;
	std::cout << "Fixed(-42.0123f) == Fixed(-42.0123f) = " << (Fixed(-42.0123f) == Fixed(-42.0123f)) << std::endl;
	std::cout << "Fixed(-42.0123f) != Fixed(-42.0123f) = " << (Fixed(-42.0123f) != Fixed(-42.0123f)) << std::endl;
	std::cout << std::endl;
    return 0;
}
