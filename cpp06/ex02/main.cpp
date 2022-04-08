#include "Base.hpp"

Base::~Base()
{}

Base    * generate(void)
{
    Base    *ret;

    srand (time(NULL));
    int rando = rand() % 3;    
    if (rando == 0)
    {
        std::cout << "Generated an object of Class A" << std::endl;
        ret = new A();
    }
    else if (rando == 1)
    {
        std::cout << "Generated an object of Class B" << std::endl;
        ret = new B();
    }
    else
    {
        std::cout << "Generated an object of Class C" << std::endl;
        ret = new C();
    }
    return (ret);
}

void      identify(Base *p)
{
    std::cout << "Pointer * identify" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    A   classA;
	B   classB;
	C   classC;

    std::cout << "Reference & identify" << std::endl;
	try 
	{
		classA = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} 
	catch (std::exception & e) 
	{
		try 
		{
			classB = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception & e) 
		{
			try 
			{
				classC = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception & e)
			{

			}
		}
	}
}


int main()
{
    Base    *base_point;

    base_point = generate();
    identify(base_point);
    identify(*base_point);
    return (0);
}