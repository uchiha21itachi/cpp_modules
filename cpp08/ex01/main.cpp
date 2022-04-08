#include "Span.hpp"
#include <cstdlib>

# define KEY ""

static std::string input;

int main()
{
	std::cout << std::endl << "Please, press ENTER" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	std::cout << std::endl << "*" << "\033[1;34m Simple tests \033[0m------------------------------------- *" << std::endl;
	if (input == KEY)
	{
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			std::cout << std::endl;
			Span sp = Span(10);
			sp.addNumber(0);
			sp.addNumber(2);
			sp.addNumber(28);
			sp.addNumber(50);
			sp.addNumber(37);
			sp.addNumber(20);
			sp.addNumber(26);
			sp.addNumber(8);
			sp.addNumber(5);
			sp.addNumber(99);
			std::cout << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			std::cout << std::endl << "test full span" << std::endl;
			Span sp = Span(2);
			try
			{
				std::cout << "try to add 0" << std::endl;
				sp.addNumber(0);
				std::cout << "try to add 2" << std::endl;
				sp.addNumber(2);
				std::cout << "try to add 28" << std::endl;
				sp.addNumber(28);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() <<  std::endl;
			}
			std::cout << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{ // BIG TEST
		try
		{
			int len = 1000;
			int array[len];
			Span sp(len);

			for (int i = 0; i < len; i++)
			{
				if (i == 235)
					array[i] = 18666; // to test if longest span is working
				else
					array[i] = i + (80000 % (i + 5555));
			}

			std::cout  << "size of sp._list: " << sp.getVector().size() << std::endl;

			int * it = array + 0;
			int * ite = array + len;
			sp.addNumberRange(it, ite);

			std::cout << "size of sp._list: "  << sp.getVector().size() << "\n" << std::endl;

			for (int i = 0; i < len; i ++)
			{
				std::cout << "["<< i << "] = "  << sp.getVector().at(i);
				if (!(i % 10 == 9))
					std::cout << " || ";
				else
					std::cout << std::endl;
			}
			std::cout << "\nThe shortest span is : "  << sp.shortestSpan() << std::endl; //2217 appears twice, maybe others too
			std::cout << "The longest span is : "  << sp.longestSpan() << std::endl;
		}
		catch(std::exception & e)
		{
			std::cerr  << e.what()  << std::endl;
		}
	}	
		{
			std::cout << std::endl << "test empty span" << std::endl;
			Span sp = Span(0);
			try
			{
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() <<  std::endl;
			}

			try
			{
				std::cout << sp.shortestSpan() << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() <<  std::endl;
			}
		}
	}
}