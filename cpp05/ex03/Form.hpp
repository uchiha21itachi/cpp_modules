#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form(void);
		Form(const Form &copy);
		Form(std::string const _name, int const _sign_grade, int const _exec_grade, std::string target);
		
		// Destructor
		virtual ~Form(void);
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Getters / Setters
		std::string const 	getName() const;
		bool 				isSigned() const;
		int 	 			getSignGrade() const;
		int					getExecGrade() const;
		std::string const	getTarget() const;
		

		//member functions
		void			execute(Bureaucrat const & executor) const;
		void			beSigned(Bureaucrat &other);


		// Exceptions
		class GradeTooHighException : public std::exception {
            public:
    			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
            public:
        		virtual const char* what() const throw();
		};
		class AlreadySignedFormException : public std::exception {
            public:
        		virtual const char* what() const throw();
		};
		class NotSignedFormException : public std::exception {
            public:
        		virtual const char* what() const throw();
		};
	private:

		//member functions
		virtual void	perform(Bureaucrat const &other) const = 0 ;

		std::string const 		_name;
		bool 					_is_signed;
		int const 				_sign_grade;
		int const 				_exec_grade;
		std::string const 		_target;

		
};
std::ostream & operator<<(std::ostream & os, Form const & other);


#endif