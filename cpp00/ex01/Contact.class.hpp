#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <string>
#include <iomanip>


class Contact {


        int             _index;
        std::string     _first_name;
        std::string     _last_name;
        std::string     _nickname;
        std::string     _phone_number;
        std::string     _darkest_secret;
        
	public:
        int             get_index(void);
        std::string     get_first_name(void);
        std::string     get_last_name(void);
        std::string     get_nickname(void);
        std::string     get_phone_number(void);
        std::string     get_darkest_secret(void);
        void            set_index(int  n);
        void            set_first_name(std::string fn);
        void            set_last_name(std::string ln);
        void            set_nickname(std::string nn);
        void            set_phone_number(std::string pn);
        void            set_darkest_secret(std::string ds);

        Contact(void);
        ~Contact(void);
};

#endif