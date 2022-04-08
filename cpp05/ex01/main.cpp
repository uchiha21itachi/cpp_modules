#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat b0;
			Form f0("First-form", 50, 50);
			std::cout << f0 << std::endl;
			b0.signForm(f0);
		}
		catch(const std::exception& e)
		{
			std::cerr  << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			Bureaucrat b1("Pascale", 80);
			Form f1("Second-form", 100, 120);
			std::cout << f1 << std::endl;
			b1.signForm(f1);
			std::cout << f1 << std::endl;
			b1.signForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr  << e.what() << std::endl;
		}
	}
	return 0;
}