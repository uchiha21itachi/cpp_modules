#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat bob("bob", 10);
	Bureaucrat david("David", 5);
	Form *f[3];

	f[0] = new ShrubberyCreationForm("Bernard");
	f[1] = new RobotomyRequestForm("Paul");
	f[2] = new PresidentialPardonForm("Michael");
	try
	{
		for (int i = 0; i < 3; i++)
			bob.executeForm(*f[i]);
		for (int i = 0; i < 3; i++)
			bob.signForm(*f[i]);
		for (int i = 0; i < 3; i++)
			bob.executeForm(*f[i]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\n" << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		for (int i = 0; i < 3; i++)
			david.signForm(*f[i]);
		for (int i = 0; i < 3; i++)
			david.executeForm(*f[i]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < 3; i++)
		delete f[i];

	return 0;
}