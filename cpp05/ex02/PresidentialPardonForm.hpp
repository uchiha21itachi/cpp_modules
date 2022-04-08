#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public Form
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(std::string target);
		
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		

	private:

		// Member function
		void			perform(Bureaucrat const &other)const;
	
};

#endif