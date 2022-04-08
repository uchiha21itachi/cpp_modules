#include "Span.hpp"

Span::Span(void) :_max_n(0)
{

}

Span::Span(unsigned int N) :_max_n(N)
{
    this->_vector.clear();
}

Span::~Span(void)
{
    std::cout << "Span destructor called \n" << std::endl;
}

Span::Span(Span const & other)
{
    *this = other;
    std::cout << "Span Copy constructor called \n" << std::endl;

}

void	addNumberRange(int * begin, int * end);


int		Span::shortestSpan(void)
{
    if (this->_vector.size() <= 1)
		throw(NoSpanToFindException());
	std::vector<int> copy = this->_vector;
	std::sort(copy.begin(), copy.end());

	std::vector<int>::iterator it = copy.begin();
	std::vector<int>::iterator ite = copy.end();
	int shortest_span = *(it + 1) - *it;

	for (std::vector<int>::iterator itf = it + 1; itf != ite; ++itf)
	{
		if (*itf - *(itf - 1) < shortest_span)
			shortest_span = (*itf - *(itf - 1));
	}
	return (shortest_span);
}

int		Span::longestSpan(void)
{
    if (this->_vector.size() <= 1)
		throw(NoSpanToFindException());

    std::vector<int> copy = this->_vector;
	std::sort(copy.begin(), copy.end());

    std::vector<int>::iterator it = copy.begin();
	std::vector<int>::iterator ite = copy.end();
    int longestSpan = *(ite - 1) - *it;
    return (longestSpan);
}

void    Span::addNumber(int new_number)
{
    if (this->_vector.size() < this->_max_n)
		this->_vector.push_back(new_number);
	else
		throw(AlreadyFullException());
}


void    Span::addNumberRange(int * begin, int * end)
{
	if (this->_vector.size() + std::distance(begin, end) <= this->_max_n)
			this->_vector.insert(this->_vector.end(), begin, end);
	else
		throw(AlreadyFullException());
}

Span & Span::operator = (Span const &other)
{
    if (this != &other)
	{
        this->_vector.erase(this->_vector.begin(), this->_vector.end());
        this->_vector.assign(other.getVector().begin(), other.getVector().end());
    }
	return *this;
}

std::vector<int> const & Span::getVector(void) const
{
    return (this->_vector);
}

const char * Span::AlreadyFullException::what() const throw()
{
	return "Error: The Span object is already full!";
}

const char * Span::NoSpanToFindException::what() const throw()
{
	return "Error: There is no span to find!";
}

std::ostream &	operator<<(std::ostream & o, Span const & rhs)
{
	std::vector<int>	v = rhs.getVector();

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it;
		if (it != v.end() - 1)
			std::cout << " ";
	}
	return (o);
}