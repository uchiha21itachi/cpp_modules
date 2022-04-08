#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <stdlib.h>


template <typename T>



class Array
{
	public:
		// Constructors
		Array(void): _array(new T[0]), _len(0) {}
        
        //unsigned int constructor
        Array(unsigned int n) : _array(new T[n]), _len(n) {}

		Array(const Array &copy):_len(copy.size())
        { 
            this->_array = new T[copy.size()];
            for (unsigned int i = 0; i < this->_len; i++)
                this->_array[i] = copy[i];
        }
		
		// Operators
		Array & operator=(Array & assign)
		{
            if (this != assign)
            {
                if (this->_array != 0)
                    delete [] this->_array;
                this->_len = assign.size();
                this->_array = new T[assign.size()];
                for (unsigned int i = 0; i < this->_len; i++)
                    this->_array[i] = assign[i];
            }
            return (*this);
        }

		// Destructor
		virtual ~Array()
        { 
            delete [] this->_array;
        }
        
        //getter
        unsigned int size(void) const 
        { 
            return this->_len; 
        }
		
        //operator
        T   &operator[](unsigned int i) const
        {
            if (i >= this->_len)
                throw OverflowException();
            return (this->_array[i]);
        }
        class OverflowException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("Error : Array overflow");
            }
        };

	private:
		T *             _array;
        unsigned int    _len; 	
};

#endif