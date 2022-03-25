#include <iostream>

int main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = -1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{	
		j = 1;
		while(j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				
				argv[j][i] = toupper(argv[j][i]);
				i++;
			}
			std::cout << argv[j];
			if (j + 1 < argc)
				std::cout << " ";
			j++;
		}
		std::cout << std::endl;
	}
	return (0);
}
