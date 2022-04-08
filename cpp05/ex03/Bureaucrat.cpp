#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(): _name("Adem"), _grade(70)
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign) 
{
	_grade = assign.getGrade();
	return *this;
}


// Getters / Setters
std::string const Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

//increment Decrement
void	Bureaucrat::increment(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrement(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

//Member Funtion
void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " has signed the form " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << this->getName() << " could not sign the form " <<
		form.getName() << "\n" << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
		try
		{
			form.execute(*this);
		}
		catch(const std::exception& e)
		{
			std::cerr << this->getName() << " cannot execute " << form.getName() << " because "
				<< e.what() << "." << std::endl;
		}
}

// Exceptions
const char * Bureaucrat::GradeTooHighException ::what() const throw()
{
	return "Grade is too high";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}


//<<operator overload
std::ostream & operator<<(std::ostream & os, Bureaucrat const & other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (os);
}
