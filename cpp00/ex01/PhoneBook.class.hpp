#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook {

        void            _update_print_string(std::string str);
        void            _print_detail_contact(int index);
        Contact         _contact_list[8];
        int             _total_contacts;
        
        public:

        PhoneBook(void);
        ~PhoneBook(void);
        void    add_contact(void);
        void    search_contact(void);
};

#endif
