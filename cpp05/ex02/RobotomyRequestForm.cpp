#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request", 72, 45, "")
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):Form (copy)
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy Request", 72, 45, target)
{
	std::cout << "\e[0;33mTarget Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


void RobotomyRequestForm::perform(Bureaucrat const &other)const
{
    std::cout << "VRRRRRRRR...KRRRRR..KRUNNNNNNCKKKKK\n";
    srand (time(NULL));
    int rando = rand() % 2;
    if (rando == 1)
        std::cout << this->getTarget() + " have been robotomized successfully by" << other.getName() << "." << std::endl;
    else
        std::cout << this->getTarget() + " have NOT been robotomized by" << other.getName() << "." << std::endl;
}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
   if (this != &assign)
		Form::operator=(assign);
	return *this;
}

