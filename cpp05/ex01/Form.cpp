#include "Form.hpp"

// Constructors
Form::Form(void): _name("default"), _is_signed(0), _sign_grade(70), _exec_grade(75)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy): _name(copy.getName()), _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade())
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string const name, int const sign_grade, int const exec_grade):
_name(name), _is_signed(0), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	_is_signed = assign.isSigned();
	return *this;
}


// Getters / Setters
std::string const Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _is_signed;
}

int Form::getSignGrade() const
{
	return _sign_grade;
}

int Form::getExecGrade() const
{
	return _exec_grade;
}

//misc
void	Form::beSigned(Bureaucrat &other)
{
	if (other.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	if (this->isSigned() == 1)
		throw(Form::AlreadySignedFormException());
	this->_is_signed = 1;
}


// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

const char * Form::AlreadySignedFormException::what() const throw()
{
	return "Form already signed";
}

std::ostream & operator<<(std::ostream & os, Form const & other)
{
	if (other.isSigned() == 1)
		os << "Form is signed" << std::endl;
	else
		os << "Form is not signed" << std::endl;
	os << "Form name -> " <<  other.getName() << "\nGrade required to sign -> " <<  other.getSignGrade() <<
	"\nGrade required to exec -> " << other.getExecGrade() << "."  << std::endl;
	return (os);
}
