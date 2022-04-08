#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
        Form	*makeForm(std::string name, std::string target);


		// Exceptions
		class WrongFormNameException : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:

    Form    *(Intern::*_forms[3]) (std::string target);
    Form    *_createShrubberyCreation(std::string target);
    Form    *_createRobotomyRequest(std::string target);
    Form    *_createPresidentialPardon(std::string target);
		
};

#endif