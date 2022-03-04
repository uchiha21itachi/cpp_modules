#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


int	check_specifier(const char *str, int i)
{
	if (str[i + 1] != '\0')
	{
		if (str[i+1] == 's' || str[i+1] == 'd' || str[i+1] == 'x' || str[i+1] == '%')
			return (1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;

	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	int	len;
	char	*temp;

	len = ft_strlen(str) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while(str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	print_string(char *str)
{

	int	i;
	int	count;

	count = 0;
	i = 0;
	while(str[i])
	{
		 count += write(1, &str[i], 1);
		 i++;
	}
	return (count);
}

int	handle_string(va_list args)
{
	int	count;
	char	*str;
	char	*temp;

	count = 0;
	temp = va_arg(args, char *);
	if (temp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(temp);
	count += print_string(str);
	free(str);
	return (count);
}

char	*reverse_string(char *str, int neg)
{
	int	len;
	char	*temp;
	int	i;

	len = ft_strlen(str);
	if (neg)
		temp = (char *)malloc(sizeof(char) * (len + 2));
	else
		temp = (char *)malloc(sizeof(char) * (len + 1));
	if(temp == NULL)
		return (NULL);
	i = 0;
	if (neg)
		temp[i++] = '-';
	while(len > 0)
	{
		temp[i] = str[len - 1];
		i++;
		len--;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_number_string(int	num)
{
	int	rem;
	int	neg;
	char	str[12];
	char	*temp;
	int	i;

	i = 0;
	neg = 0;
	if (num < 0)
	{
		neg = 1;
		num = num * -1;
	}
	while( num > 9 )
	{
		rem = num % 10;
		str[i++] = rem + 48;
		num = num / 10;
	}
	str[i++] = num + 48;
	str[i] = '\0';
	temp = reverse_string(str, neg);
	return (temp);
}

int	handle_numbers(va_list args)
{
	int	num;
	char	*num_str;
	int	count;

	count = 0;
	num = va_arg(args, int);
	num_str = get_number_string(num);
	if(num_str == NULL)
		return (0);
	count += print_string(num_str);
	free(num_str);
	return (count);
}

int	handle_unsigned(va_list args)
{
	char 		*rep;
	char		str[50];
	char		*ptr;
	int		count;
	unsigned int	num;
	
	
	num = va_arg(args, unsigned int);
	count = 0;
	rep = ft_strdup("0123456789abcdef");
	if (rep == NULL)
		return (0);
	ptr = &str[49];
	*ptr = '\0';
	while(1)
	{
		*--ptr = rep[num % 16];
		num = num / 16;
		if (num == 0)
			break;
	}
	free(rep);
	count += print_string(ptr);
	return (count);
}

int	handle_specifier(const char *format, int i, va_list args)
{
	int	count;

	count = 0;
	if (format[i + 1] == 's')
		count += handle_string(args);
	else if (format[i + 1] == 'd')
		count += handle_numbers(args);
	else if (format[i + 1] == 'x')
		count += handle_unsigned(args);
	else if (format[i + 1] == '%')
	{
		count += write(1, "%", 1);
	}
	return (count);
}

int 	ft_printf(const char *format, ...)
{
	va_list		args;
	int		count;
	int		i;

	count = 0;
	va_start(args, format);
	i = 0;
	while(format[i])
	{
		if ( format[i] == '%' && (check_specifier(format, i) == 1))
		{
			count += handle_specifier(format, i, args);
			i += 2;
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	return (count);
	
}



int main(void)
{
	int	i;
	int	j;
	char	*str = NULL;

	
	i = 0;
	j = 0;

	i += ft_printf("%x\n", 2143);	
	j += printf("%10.6x\n", 2143);	

	i += ft_printf("%x\n", 9832983);	
	j += printf("%x\n", 9832983);	

	i += ft_printf("%x\n", -1212);	
	j += printf("%x\n", -1212);	

	i += ft_printf("%x\n", 123456);	
	j += printf("%x\n", 123456);

	i += ft_printf("%x%d%s%%\n", 123456, 123456,"12345");	
	j += printf("%x%d%s%%\n", 123456, 123456,"12345");	

	printf("i [%d] j [%d]\n\n",i, j);

// printf("-----------------------------------------STRINGS ONLY ---------------------");
	i = ft_printf("hello %s %s\n", "world", "blabla");	
	j = printf("hello %s %s\n", "world", "blabla");	
	printf("i [%d] j [%d]\n\n",i, j);

	i = ft_printf("hello %s %s\n", str, str);	
	j = printf("hello %s %s\n", str, str);	
	printf("i [%d] j [%d]\n\n",i, j);
// printf("-----------------------------------------INTEGERS ONLY ---------------------");
 	i =0;
	j =0;	

	i += ft_printf("hello %d \n", 2147483647);	
	j += printf("hello %d \n", 2147483647);	
	
	i += ft_printf("hello %d \n", -2147483647);	
	j += printf("hello %d \n", -2147483647);	
	
	i += ft_printf("hello %d \n", 12345);	
	j += printf("hello %d \n", 12345);	
	
	i += ft_printf("hello %d \n", -12345);	
	j += printf("hello %d \n", -12345);	
	
	i += ft_printf("hello %d \n", 0);	
	j += printf("hello %d \n", 0);	
	
	i += ft_printf("hello %d \n", -0);	
	j += printf("hello %d \n", -0);	
	
	i += ft_printf("hello %d \n", -42323);	
	j += printf("hello %d \n", -42323);	
	
	i += ft_printf("hello %d \n", 8898129);	
	j += printf("hello %d \n", 8898129);	
	printf("I is [%i]\n\n", i);	
 	printf("J is [%i]\n\n", j);


 	i = 	ft_printf("hello %s num1 %d num2 %d num3 %d null string %s \n", "world", 10, 20012, -214748, str);	
 	j = 	printf("hello %s num1 %d num2 %d num3 %d null string %s \n", "world", 10, 20012, -214748, str);	
	printf("i [%d] j [%d]",i, j);
	
	
	
	
 	return (0);
 }



/*
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


int main()
{
	int	j;
	int	i;
	char	*str;


	i = 0;
	j = 0;
	str = ft_strdup("lol aeldoaed LOKL\n");
	j = ft_printf("hello %s %s\n%d %d %d %x\n", "world" ,str, -123456, 4242, 0, 92929);
	i = printf("hello %s %s\n%d %d %d %x\n", "world" ,str, -123456, 4242, 0, 92929);
	printf("i [%d] j[%d]\n", i, j);
	free(str);
	(void)j;
	return (0);
}

*/
