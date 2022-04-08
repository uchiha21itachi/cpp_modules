#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP


# include <iostream>
# include <string>
# include <fstream>

# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(std::string target);
		
		// Destructor
		~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		

		// Exceptions
		class OpeningShrubberyFileException : public std::exception {
            public:
    			virtual const char* what() const throw();
		};
	
	private:

		// Member function
		void	perform(Bureaucrat const &other)const;

};

#endif