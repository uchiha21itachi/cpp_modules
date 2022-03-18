#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef	struct	s_screen{

	int	width;
	int	height;
	char	back_char;
	char	*space;

}		t_screen;

typedef	struct	s_rect{

	char	empty_check;
	float	xl;
	float	yl;
	float	width;
	float	height;
	char	draw_char;

}		t_rect;

void	ft_write(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


void	print_screen(t_screen *base)
{

	int	i;
	int	j;
	int	count;


	i = 0;
	j = 0;
	count = 0;
	while(i < base->width)
	{
		j = 0;
		while(j < base->height)
		{
			write(1, &base->space[count], 1);
			count++;
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	check_rect_params(t_rect *rect)
{
	if (rect->empty_check != 'r' && rect->empty_check != 'R')
		return (1);
	if (rect->xl < 0 || rect->yl < 0)
		return (1);
	return (0);
}

int	check_point(float x, float y, t_rect *rect)
{
	if (x < rect->xl || rect->xl + rect->width < x || y < rect->yl || rect->yl + rect->height < y)
		return (0);
	if (((x - rect->xl) < 1.00000000 || (rect->xl + rect->width) - x < 1.00000000) || ((y - rect->yl) < 1.00000000 || (rect->yl + rect->height) - y < 1.00000000))
		return (1);
	return (2);
}

void	print_rect(t_screen *base, t_rect *rect)
{
	int	i;
	int	j;
	int	ret;
	int	num;

	i = 0;
	j = 0;
	ret = 0;
	num = 0;
	while(i < base->width)
	{
		j = 0;
		while(j < base->height)
		{
			ret = check_point((float)i, (float)j, rect);
			if (ret == 1)
			{
				num = (j * base->width) + i;
				base->space[num] = rect->draw_char;		
			}
			else if (ret == 2 && rect->empty_check == 'R')
			{
				num = (j * base->width) + i;
				base->space[num] = rect->draw_char;
			}
			j++;
		}
		i++;
	}	
}

int	get_rects(t_screen *base, FILE *config)
{
	t_rect		rect;
	int		i;
	int		ret = 0;

	(void)base;
	i = 0;
	i = fscanf(config, "%c %f %f %f %f %c\n", &rect.empty_check, &rect.xl, &rect.yl, &rect.width, &rect.height, &rect.draw_char);
	if (i != 6)
		return (1);
	while (i == 6)
	{
		ret = check_rect_params(&rect);
		if (ret == 1)
		{
			ft_write("Error in rect args\n");
			return (1);
		}
		print_rect(base, &rect);
		i = fscanf(config, "%c %f %f %f %f %c\n", &rect.empty_check, &rect.xl, &rect.yl, &rect.width, &rect.height, &rect.draw_char);
	}
	if (i != -1)
		return (1);
	return (0);
}

int	start_parsing(FILE *config)
{
	int		ret;
	t_screen	*base;
	int		i;

	ret = 0;
	base = (t_screen *)malloc(sizeof(t_screen));
	if (base == NULL)
	{
		ft_write("Error: unexpected malloc error\n");
		return (1);
	}
	ret = fscanf(config, "%d %d %c\n", &base->width, &base->height, &base->back_char);
	if (ret != 3)
	{
		free(base);
		ft_write("Error: fscanf did not return 3 in parse screen\n");
		return (1);
	}
	if (base->width < 0 || base->width > 300 || base->height < 0 || base->height > 300)
	{
		free(base);
		ft_write("Error: base width or height is wrong\n");
		return (1);
	}
	ret = (base->width * base->height);
	base->space = (char *)malloc(sizeof(char) * (ret + 1));
	if ( base->space == NULL)
	{
		free(base);
		return (1);
	}
	base->space[ret] = '\0';
	i = 0;
	while(i <= ret)
	{
		base->space[i] = base->back_char;
		i++;
	}
	i = get_rects(base, config);
	if ( i == 1)
	{
		free(base->space);
		free(base);
		return (1);
	}
	print_screen(base);
	free(base->space);
	free(base);
	return (0);
}

int 	main(int ac, char **av)
{
	FILE	*config;
	int	ret;

	if (ac != 2)
	{
		ft_write("Error: Wrong args\n");
		return (1);
	}
	config = fopen(av[1], "r");
	if (config == NULL)
	{
		ft_write("Error: cannot open the file\n");
		return (2);
	}
	ret = start_parsing(config);
	fclose(config);
	if (ret == 1)
	{
		ft_write("Error: wrong config file\n");
		return (3);
	}
	return (0);
}
