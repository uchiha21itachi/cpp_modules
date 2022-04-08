#include "Brain.hpp"

Brain::Brain(void)
{
    std::string some[4] = {"MakeNoise", "DoNothing", "GoEat", "TimeToSleep"};

    for (int i = 0; i < 100 ; i++)
    {
        this->ideas[i] = some[i % 4];
    }
    std::cout << "(Brain Default):\t Created a new brain" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "(Brain Destructor):\t Destroyed a brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "(Brain Copy):\t A brain has been created by data of another brain" << std::endl;
}


Brain & Brain::operator = (const Brain &other)
{
    std::cout << "(Brain operator=):\t A brain has been created by data of another brain" << std::endl;
    for(int i = 0; i < 100 ; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    return *this;
}

std::string const  & Brain::getIdea(int i) const
{
    if (i < 0 || i > 100)
    {
        std::cout << "index for finding idea is out of bounds\nPlease enter [1 - 100]\nReturning ideas[0]" << std::endl;
        return (this->ideas[0]);
    }
    else if (i == 0)
        return (this->ideas[0]);
    return (this->ideas[i - 1]);
}

void    Brain::setIdea(int i, std::string new_idea)
{
    this->ideas[i] = new_idea;
}