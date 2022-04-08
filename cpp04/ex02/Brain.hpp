#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

    public :

        Brain(void);
        ~Brain(void);
        Brain(const Brain &other);
        Brain & operator = (const Brain &other);

        /*
            Getters and setters
        */

        std::string const & getIdea(int i) const;
        void setIdea(int i, std::string new_idea);

    private :

        std::string ideas[100];
};

#endif