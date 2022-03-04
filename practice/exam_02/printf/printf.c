#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


int	ft_strlen(char *str)
{
	int	i;
	i = 0;

	while(str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}

int	check_specifier(const char *input, int i)
{

	if(input[i + 1] != '\0')
	{
		if (input[i + 1] == 's' || input [i + 1] == 'd' || input[i + 1] == 'x' || input[i + 1] == '%')
			return (1);
	}
	return (0);
}


int	handle_strings(va_list args)
{
	int	j;
	char	*temp;

	j = 0;
	temp = va_arg(args, char *);
	if (temp == NULL)
	{
		j += write(1, "(", 1);
		j += write(1, "n", 1);
		j += write(1, "u", 1);
		j += write(1, "l", 1);
		j += write(1, "l", 1);
		j += write(1, ")", 1);
		return (j);
	}	
	while(temp[j])
	{
		write(1, &temp[j], 1);
		j++;
	}
	return(j);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*temp;
	int 	len;

	len = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (len + 1 ));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while(str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char 	*reverse_string(char *str, int neg)
{
	int 	len;
	int 	i;
	char	*num_str;

	len = ft_strlen(str);
	if (neg)
		num_str = (char *)malloc(sizeof(char) * len + 2);
	else
		num_str = (char *)malloc(sizeof(char) * len + 1);
	if (num_str == NULL)
		return(NULL);
	i = 0;
	if (neg)
		num_str[i++] = '-';
	while (--len >= 0)
	{
		num_str[i] = str[len];
		i++;
	}
	num_str[i] = '\0';
	return (num_str);
}

char	*get_num_string(int num)
{
	char	*num_str;
	char	str[12];
	int		rem;
	int		neg;
	int		i;

	if (num > 2147483647)
		return (NULL);
	if (num == -2147483647)
	{
		num_str = ft_strdup("-2147482647");	
		return (num_str);
	}
	neg = 0;
	i = 0;
	if (num < 0)
	{
		neg = 1;
		num = num * -1;
	}
	while(num > 9)
	{
		rem = num % 10;
		str[i++] = rem + 48;
		num = num / 10;
	}
	str[i++] = num + 48;
	str[i] = '\0';
	num_str = reverse_string(str, neg);
	return (num_str);
}

int	handle_int(va_list args)
{
	int		num;
	int		count;
	char	*str;
	
	count = 0;
	num = va_arg(args, int);
	str = get_num_string(num);
	count += ft_putstr(str);
	if (str)
		free(str);
	return (count);
}

int		convert_x(unsigned int num)
{
	char	buffer[50];
	char	*rep;
	int		base;
	char	*str;
	int		count;

	rep = ft_strdup("0123456789abcdef");
	if (rep == NULL)
		return (0);
	base = 16;
	str = &buffer[49];
	*str = '\0';
	while (1)
	{
		*--str = rep[num % base];
		num = num / base;
		if (num == 0)
			break;
	}
	count = 0;
	free(rep);
	count = ft_putstr(str);
	return (count);
}

int	handle_unsigned(va_list args)
{
	unsigned int	num;
	int				count;

	count = 0;
	num = va_arg(args, unsigned int);
	count = convert_x(num);
	return (count);
}

int	handle_specifier(const char *input , int i, va_list args)
{
	int	count;

	count = 0;

	if (input[i+1] == 's')
		count = handle_strings(args);
	else if (input[i+1] == 'd')
		count = handle_int(args);
	else if (input[i+1] == 'x')
		count = handle_unsigned(args);
	else if (input[i+1] == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int	count;
	va_list	args;
	int	i;


	count = 0;
	i = 0;
	va_start(args, input);
	
	while (input[i])
	{
		if (input[i] == '%' && check_specifier(input, i) == 1)
		{
			count += handle_specifier(input, i, args);
			i += 2;
		}
		else
		{	
			count += write(1, &input[i], 1);
			i++;
		}
	}
	return (count);
}










int main(void)
{
	char *str = NULL;
	printf("\n\nTEST %%s\n\n");
	printf("\n___TEST %%s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", str));
	printf("Original - %d\n", printf("|%s|\n", str));

	printf("\n___TEST %%ss___\n");
	printf("No original - %d\n", ft_printf("|%ss|\n", "str"));
	printf("Original - %d\n", printf("|%ss|\n", "str"));

	printf("\n___TEST %%20s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", "hello world\n\n"));
	printf("Original - %d\n", printf("|%s|\n", "hello world\n\n"));

	printf("\n___TEST %%2s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", "hello\0world"));
	printf("Original - %d\n", printf("|%s|\n", "hello\0world"));



	printf("\n\nTEST %%d\n\n");
	int num = 0;
	printf("\n___TEST %%d___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", num));
	printf("Original - %d\n", printf("|%d|\n", num));

	printf("\n___TEST %%dd___\n");
	printf("No original - %d\n", ft_printf("|%dd|\n", num));
	printf("Original - %d\n", printf("|%dd|\n", num));

	printf("\n\nTEST %%x\n\n");
	unsigned int un = 0;
	printf("\n___TEST %%x___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", un));
	printf("Original - %d\n", printf("|%x|\n", un));

	printf("\n___TEST %%xx___\n");
	printf("No original - %d\n", ft_printf("|%xx|\n", un));
	printf("Original - %d\n", printf("|%xx|\n", un));

	
	return (0);
}












// int main(void)
// {
// 	int	i;
// 	int	j;
// 	char	*str = NULL;

	
// 	i = 0;
// 	j = 0;

// 	i += ft_printf("%x\n", 2143);	
// 	i += ft_printf("%x\n", 9832983);	
// 	i += ft_printf("%x\n", -1212);	
// 	i += ft_printf("%x\n", 123456);	

// 	i += ft_printf("%x%d%s%%\n", 123456, 123456,"12345");	
// 	j += printf("%x%d%s%%\n", 123456, 123456,"12345");	



// 	j += printf("%x\n", 2143);	
// 	j += printf("%x\n", 9832983);	
// 	j += printf("%x\n", -1212);	
// 	j += printf("%x\n", 123456);

// 	printf("i [%d] j [%d]\n\n",i, j);

// // // printf("-----------------------------------------STRINGS ONLY ---------------------");
// // 	i = ft_printf("hello %s %s\n", "world", "blabla");	
// // 	j = printf("hello %s %s\n", "world", "blabla");	
// // 	printf("i [%d] j [%d]\n\n",i, j);

// // 	i = ft_printf("hello %s %s\n", str, str);	
// // 	j = printf("hello %s %s\n", str, str);	
// // 	printf("i [%d] j [%d]\n\n",i, j);
// // // printf("-----------------------------------------INTEGERS ONLY ---------------------");
// //  	i =0;
// // 	j =0;	

// // 	i += ft_printf("hello %d \n", 2147483647);	
// // 	i += ft_printf("hello %d \n", -2147483647);	
// // 	i += ft_printf("hello %d \n", 12345);	
// // 	i += ft_printf("hello %d \n", -12345);	
// // 	i += ft_printf("hello %d \n", 0);	
// // 	i += ft_printf("hello %d \n", 0);	
// // 	i += ft_printf("hello %d \n", -42323);	
// // 	i += ft_printf("hello %d \n", 8898129);	
// // 	printf("I is [%i]\n\n", i);
	
// // 	j += printf("hello %d \n", 2147483647);	
// // 	j += printf("hello %d \n", -2147483647);	
// // 	j += printf("hello %d \n", 12345);	
// // 	j += printf("hello %d \n", -12345);	
// // 	j += printf("hello %d \n", 0);	
// // 	j += printf("hello %d \n", 0);	
// // 	j += printf("hello %d \n", -42323);	
// // 	j += printf("hello %d \n", 8898129);	
// // 	printf("J is [%i]\n\n", j);


// // 	i = 	ft_printf("hello %s num1 %d num2 %d num3 %d null string %s \n", "world", 10, 20012, -214748, str);	
// // 	j = 	printf("hello %s num1 %d num2 %d num3 %d null string %s \n", "world", 10, 20012, -214748, str);	
// // 	printf("i [%d] j [%d]",i, j);
	
	
	
	
// 	return (0);
// }

