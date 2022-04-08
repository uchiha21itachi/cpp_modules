#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>

class MutantStack : public std::stack<T>
{
	public:
		//Canonical Form

		MutantStack(void){}
		virtual ~MutantStack(void){}
		MutantStack(MutantStack const & other): std::stack<T>(other) {}
		MutantStack & operator = (MutantStack const & other)
		{
			if (*this == other)
				return *this;
			std::stack<T>::operator=(other);
		}

		typedef typename	std::stack<T>::container_type::iterator iterator;

		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}

	private:
};


#endif
