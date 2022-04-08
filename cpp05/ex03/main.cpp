#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Intern  		Yash;
	Bureaucrat 		amine("Amine", 4);
	Form*   		forms[4];

	for (int i = 0; i < 4; i++)
	{
		forms[i] = 0;
	}
	try
	{
		forms[0] = Yash.makeForm("robotomy request", "Bender");
		forms[1] = Yash.makeForm("shrubbery creation", "Paul");
		forms[2] = Yash.makeForm("presidential pardon", "Theo");
		std::cout << "\n\n" << std::endl;

		for (int i = 0; i < 4; i++)
		{
			if (forms[i] != 0)
			{
				amine.signForm(*forms[i]);
				amine.signForm(*forms[i]);
				amine.executeForm(*forms[i]);
			}
		}
		forms[3] = Yash.makeForm("pardon whaatt>>??", "Hercules");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 4; i++)
	{
		if (forms[i] != 0)
			delete forms[i];
	}
}
