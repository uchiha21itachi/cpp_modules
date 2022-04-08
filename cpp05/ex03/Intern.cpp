#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
    this->_forms[0] = &Intern::_createPresidentialPardon;
    this->_forms[1] = &Intern::_createShrubberyCreation;
    this->_forms[2] = &Intern::_createRobotomyRequest;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


Form	*Intern::makeForm(std::string name, std::string target)
{
    std::string     str[3] = { "presidential pardon", "shrubbery creation", "robotomy request" };
    Form            *ret_form;

    for(int i = 0; i < 3; i++)
    {
        if (name.compare(str[i]) == 0)
        {
            ret_form = (this->*_forms[i])(target);
            std::cout << "Intern creates " << name << " form." << std::endl;
            return (ret_form);
        }
    }
    throw Intern::WrongFormNameException();
    return (NULL); 
}

Form	*Intern::_createShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::_createRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::_createPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}




// Exceptions
const char * Intern::WrongFormNameException::what() const throw()
{
	return "Wrong Form Name";
}
