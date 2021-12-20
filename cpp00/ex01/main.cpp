#include "PhoneBook.class.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	list;
	std::string	input;
	int		ret;

	(void)argc;
	(void)argv;
	ret = 1;
	std::cout << "-----------------WELCOME TO MY CRAPPY PHONEBOOK--------------\n\n" << std::endl;
	while(ret)
	{
		std::cout << "------------------------------------------\n";
		std::cout << "Please select your operation" << std::endl;
		std::cout << "\n       ADD|     SEARCH|      EXIT|\n" << std::endl;	
		std::cout << "Input - ";
		std::cin >> input;
		for(int i = 0; i < (int)input.length(); i++)
			input[i] = toupper(input[i]);
		if(input == "EXIT")
			ret = 0;
		else if (input == "SEARCH")
			list.search_contact();
		else if (input == "ADD")
			list.add_contact();
	}	
}
