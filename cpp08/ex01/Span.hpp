#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iterator>
# include <vector>
# include <algorithm>

class Span
{
	class AlreadyFullException: public std::exception
	{
		public:
			const char * what() const throw();
	};
	class NoSpanToFindException: public std::exception
	{
		public:
			const char * what() const throw();
	};
	public:
		//Canonical Form

		Span(void);
		~Span(void);
		Span(Span const & other);
		Span & operator = (Span const & other);

		// Other constructor

		Span(unsigned int N);

		//Misc
        
		void						addNumber(int new_number);
		void						addNumberRange(int * begin, int * end);
		int							shortestSpan(void);
		int							longestSpan(void);

		//Getters

		std::vector<int> const &	getVector(void) const;

	private:
		unsigned int		_max_n;
		std::vector<int>	_vector;
};

std::ostream &	operator<<(std::ostream & o, Span const & rhs);

#endif