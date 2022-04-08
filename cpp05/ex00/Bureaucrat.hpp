#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string const name, int grade);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		
		// Getters / Setters
		std::string const 	getName() const;
		int 				getGrade() const;

		//Increment Decrement
		void	increment(void);
		void	decrement(void);
		
		// Exceptions
		class GradeTooHighException  : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	private:
		std::string  const	_name;
		int 				_grade;
		
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & other);

#endif