#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include  <stdlib.h>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(std::string target);
		
		// Destructor
		~RobotomyRequestForm();
		
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
	
	private:
	
		// Member function
		void	perform(Bureaucrat const &other)const;

};

#endif