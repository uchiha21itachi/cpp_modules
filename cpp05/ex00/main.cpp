#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat b0;
			std::cout << "[Guetters and operators overload <<]" << std::endl;
			std::cout << "getName(): " << b0.getName() << std::endl;
			std::cout << "getGrade(): " << b0.getGrade() << std::endl;
			std::cout << b0 << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try
		{
			Bureaucrat b1("Zed", 151);
		}
		catch(std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try
		{
			Bureaucrat b2("lulu", 0);
		}
		catch(std::exception & e)
		{
			std::cerr  << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try
		{
            Bureaucrat b3("Luffy-Gear5", 150);
			std::cout << b3 << std::endl;
			b3.increment();
			std::cout << b3 << std::endl;
			b3.decrement();
			std::cout << b3 << std::endl;
			b3.decrement();
			std::cout << b3 << std::endl;
		}
		catch(std::exception& e)
        {
			std::cerr  << e.what() << std::endl;
		}
		try
		{
            Bureaucrat b4("Nami", 1);
			std::cout << b4 << std::endl;
			b4.decrement();
			std::cout << b4 << std::endl;
			b4.increment();
			std::cout << b4 << std::endl;
			b4.increment();
			std::cout << b4 << std::endl;
		}
		catch(std::exception& e)
        {
			std::cerr  << e.what() << std::endl;
		}
	}

	return 0;
}