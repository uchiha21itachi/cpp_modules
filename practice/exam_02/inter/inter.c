#include <stdio.h>
#include <unistd.h>


int	ft_strlen(char *str)
{

	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	check_presence(char c, char *str2)
{
	int i;

	i = 0;
	while(str2[i])
	{
		if (str2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_strings(char *str1, char *str2)
{

	int	i;
	char	temp[ft_strlen(str1)];
	int	j;

	
	j = 0;
	i = 0;
	temp[ft_strlen(str1)] = '\0';
	while(str1[i] != '\0')
	{
		if (check_presence(str1[i], str2) == 1 && (check_presence(str1[i], temp) == 0))
		{
			temp[j] = str1[i];
			j++;
			write(1, &str1[i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{


	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	check_strings(argv[1], argv[2]);
	return (1);
}
