#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation", 145, 137, "")
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery Creation", 145, 137, target)
{
	std::cout << "\e[0;33mTarget Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

void ShrubberyCreationForm::perform(Bureaucrat const &other)const
{
	std::ofstream ofs;
	std::string outfile(this->getTarget() + "_shrubbery");
	ofs.open(outfile.c_str(), std::ios::trunc);
	if (ofs.is_open())
	{
		ofs << "         v" << std::endl;
		ofs << "        >X<" << std::endl;
		ofs << "         A" << std::endl;
		ofs << "        dPb" << std::endl; 
		ofs << "      .d\\PPb." << std::endl;
		ofs << "    .dPiPP\\PPb." << std::endl;
		ofs << "       dPP@b" << std::endl;
		ofs << "      d\\PPPib" << std::endl; 
		ofs << "    .dPPP\\PPPb" << std::endl;
		ofs << "  .dPP@PPPP\\PPib." << std::endl;
		ofs << "      dPPiPPb" << std::endl;
		ofs << "     d\\PPPP@Pb" << std::endl;
		ofs << "  .dP@PP\\PPPPP@b." << std::endl;
		ofs << ".dPPPPiPPP\\PPPPPPb." << std::endl;
		ofs << "        ###" << std::endl;
		ofs << "        ###" << std::endl;
		ofs << "        ###" << std::endl;		
		ofs << other.getName();
		ofs.close();
	}
	else
		throw (OpeningShrubberyFileException());
}

// Exceptions
const char * ShrubberyCreationForm::OpeningShrubberyFileException::what() const throw()
{
	return "Cannot open shrubbery file";
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this != &assign)
		Form::operator=(assign);
	return *this;
}

