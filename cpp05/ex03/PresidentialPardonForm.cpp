#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential pardon", 25, 5, "")
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):Form(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential pardon", 25, 5, target)
{
	std::cout << "\e[0;33mTarget Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}

void PresidentialPardonForm::perform(Bureaucrat const &other)const
{
	std::cout << this->getTarget() << " has been pardoned by " << other.getName() << "." << std::endl;
}

// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	if (this != &assign)
		Form::operator=(assign);
	return *this;
}

