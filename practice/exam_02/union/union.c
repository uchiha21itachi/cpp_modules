#include <unistd.h>
#include <stdio.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	print_string(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	check_double(char *str, char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	check_strings(char *str1, char *str2)
{

	int	i, j;
	int	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	char	temp[len];

	temp[len] = 0;
	i = 0;
	j = 0;
	while(str1[i])
	{
		if (check_double(temp, str1[i]) == 1)
		{
			temp[j] = str1[i];
			j++;
		}
		i++;
	}
	i = 0;
	while(str2[i])
	{
		if(check_double(temp, str2[i]) == 1)
		{
			temp[j] = str2[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	print_string(temp);
}

int main(int ac, char **av)
{


	if (ac == 3)
	{
		check_strings(av[1], av[2]);
	}
	write(1, "\n", 1);

}
