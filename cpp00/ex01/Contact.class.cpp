#include "Contact.class.hpp"

//should be removed?
//----------------------
Contact::Contact(void){
    // std::cout << "Welcome to the Contact constructor" << std::endl;
}

Contact::~Contact(void){
    // std::cout << "Contact Desctructor called." << std::endl;
}
//-------------------------

void    Contact::set_index(int  n){
    this->_index = n;
}

void    Contact::set_first_name(std::string fn){
    this->_first_name = fn;
}

void    Contact::set_last_name(std::string ln){
    this->_last_name = ln;
}

void    Contact::set_nickname(std::string nn){
    this->_nickname = nn;
}

void    Contact::set_phone_number(std::string pn){
    this->_phone_number = pn;
}

void    Contact::set_darkest_secret(std::string ds){
    this->_darkest_secret = ds;
}

int    Contact::get_index(void){
    return (this->_index);
}

std::string    Contact::get_first_name(void){
    return (this->_first_name);
}

std::string    Contact::get_last_name(void){
    return (this->_last_name);
}

std::string    Contact::get_nickname(void){
    return (this->_nickname);
}

std::string    Contact::get_phone_number(void){
    return (this->_phone_number);
}

std::string    Contact::get_darkest_secret(void){
    return (this->_darkest_secret);
}