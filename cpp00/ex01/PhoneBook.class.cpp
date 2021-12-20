#include "PhoneBook.class.hpp"
#include <string>

PhoneBook::PhoneBook(void) {
    std::cout << "Hello From PhoneBook Constructor" << std::endl;    
    this->_total_contacts = 0;
}

PhoneBook::~PhoneBook(void){ 
    std::cout << "PhoneBook destructor called" << std::endl;
}

void PhoneBook::_update_print_string(std::string str)
{
    std::string new_str;
    int         len;
    int         num;

    len = str.size();
    if(len < 0)
        return;
    if (len == 10)
    {
        std::cout << str << "|";
    }
    else if (len > 10)
    {
        for (int i = 0; i < 9; i++)
        {
            std::cout << str[i];
        }
        std::cout << ".|";
    }
    else
    {
        num = 10 - len;
        for (int i = 0; i < num; i++)
        {
            std::cout << " ";
        }
        std::cout << str << "|";
    }
}

void    PhoneBook::_print_detail_contact(int index)
{
    std::cout << "\nIndex - " << this->_contact_list[index -1].get_index() << std::endl;
    std::cout << "\nFirst Name - " << this->_contact_list[index -1].get_first_name() << std::endl;
    std::cout << "\nLast Name - " << this->_contact_list[index -1].get_last_name() << std::endl;
    std::cout << "\nNickName - " << this->_contact_list[index -1].get_nickname() << std::endl;
    std::cout << "\nPhone Number - " << this->_contact_list[index -1].get_phone_number() << std::endl;
    std::cout << "\nDarkest Secret - " << this->_contact_list[index -1].get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact(void)
{
    int     i;
    int     j;
    int     input = 0;

    i = 0;
    std::cout << "Inside search contact" << std::endl;
    if (this->_total_contacts == 0)
    {
        std::cout << "Empty PhoneBook" << std::endl;
    }
    if (this->_total_contacts >= 8)
        j = 8;
    else
        j = this->_total_contacts;
    std::cout << "\n\n----------------------------------------------" << std::endl;
    _update_print_string("Index");
    _update_print_string("First_Name");
    _update_print_string("Last_name");
    _update_print_string("Nickname");
    std::cout << "\n----------------------------------------------\n" << std::endl;
    while(i < j)
    {
        std::string     temp;
        std::cout << "         ";
        std::cout << this->_contact_list[i].get_index();
        std::cout << "|";
        _update_print_string(this->_contact_list[i].get_first_name());
        _update_print_string(this->_contact_list[i].get_last_name());
        _update_print_string(this->_contact_list[i].get_nickname());
        std::cout << std::endl;
        i++;
    }
    std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n" << std::endl;
    i = 0;
    while (i == 0)
    {
        std::cout << "Please enter the index to see details" << std::endl;
        std::cin >> input;
        std::cout << "\n";
        std::cout << "\n----------------------------------------------\n" << std::endl;
        if (input > 0 && input <= 8)
        {
            this->_print_detail_contact(input);
            i = 1;
        }
        else if (input == 0)
            i = 1;
        else
            std::cout << "Please enter correct output -- usage - [0 = exit] [1-8 = contact]";
    }

}

void PhoneBook::add_contact(void)
{
    std::string     input;
    int             i;

    i = this->_total_contacts % 8;
    this->_contact_list[i].set_index(i + 1);
    std::cout << "\n\nPlease enter the following fields" << std::endl;
    std::cout << "First_Name - ";
    std::cin >> input;
    std::cout << "\n";
    this->_contact_list[i].set_first_name(input);
    std::cout << "Last_Name - ";
    std::cin >> input;
    std::cout << "\n";
    this->_contact_list[i].set_last_name(input);
    std::cout << "Nickname - ";
    std::cin >> input;
    std::cout << "\n";
    this->_contact_list[i].set_nickname(input);
    std::cout << "Phone_Number - ";
    std::cin >> input;
    std::cout << "\n";
    this->_contact_list[i].set_phone_number(input);
    std::cout << "Darkest_Secret - ";
    std::cin >> input;
    std::cout << "\n";
    this->_contact_list[i].set_darkest_secret(input);
    this->_total_contacts++;
}
