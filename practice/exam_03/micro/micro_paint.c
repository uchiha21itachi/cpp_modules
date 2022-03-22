#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_screen{

	int	width;
	int	height;
	char	back_char;
	char	*space;

}		t_screen;


typedef struct	s_rect{

	char	empty;
	float	xr;
	float	yr;
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

void	print_base(t_screen *base)
{
	int	i;
	int	j;

	j = 0;
	while(j < base->height)
	{
		i = 0;
		while(i < base->width)
		{
			write(1, &base->space[(base->width * j) + i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

void	fill_base_space(t_screen *base)
{
	int	i;
	int	size;

	i = 0;
	size = base->height * base->width;
	while(i < size)
	{
		base->space[i] = base->back_char;
		i++;
	}
	base->space[size] = '\0';
}

int	check_if_in(float x, float y, t_rect *rect)
{
	if (x < rect->xr || y < rect->yr || rect->xr + rect->width < x || rect->yr + rect->height < y)
		return (0);
	if (x - rect->xr < 1.00000000 || y - rect->yr < 1.00000000 || (rect->xr + rect->width) - x < 1.00000000
		||(rect->yr + rect->height) - y < 1.00000000)
		return (1);
	return (2);
}

void	update_base(t_screen *base, t_rect *rect)
{
	int	ret;
	int	temp;
	int	i;
	int	j;

	j = 0;
	ret = 0;
	temp = 0;
	while (j < base->height)
	{
		i = 0;
		while (i < base->width)
		{
			ret = check_if_in((float)i, (float)j, rect);
			if (ret == 1 || (ret == 2 && rect->empty == 'R'))
			{
				temp = (base->width * j) + i;
				base->space[temp] = rect->draw_char;		
			}
			i++;
		}
		j++;
	}
}

int	get_rects(t_screen *base, FILE *config)
{
	t_rect		rect;
	int		ret;


	ret = fscanf(config,"%c %f %f %f %f %c\n", &rect.empty, &rect.xr, &rect.yr, &rect.width, &rect.height, &rect.draw_char);
	while (ret == 6)
	{
		if(rect.empty != 'r' && rect.empty != 'R')
			return (1);
		if (rect.width <= 0.00000000 || rect.height <= 0.00000000)
			return (1);
		update_base(base, &rect);
		ret = fscanf(config,"%c %f %f %f %f %c\n", &rect.empty, &rect.xr, &rect.yr, &rect.width, &rect.height, &rect.draw_char);
	}
	if (ret != -1)
	{
		return (1);
	}
	return (0);
}

int	start_parsing(FILE *config)
{
	int		ret;
	t_screen	*base;
	int		size;

	base = (t_screen *)malloc(sizeof(t_screen));
	if (base == NULL)
		return (1);
	ret = fscanf(config, "%d %d %c\n", &base->width, &base->height, &base->back_char);
	if (ret != 3 || base->width < 1 || base->height < 1 || base->width > 300 || base->height > 300)
	{
		free(base);
		return (1);
	}
	size = base->width * base->height;
	base->space = (char *)malloc(sizeof(char) * (size + 1));
	if (base->space == NULL)
	{
		free(base);
		return (1);
	}
	base->space[size] = '\0';
	ret = 0;
	fill_base_space(base);
	ret = get_rects(base, config);
	if (ret == 1)
	{
		free(base->space);
		free(base);
		return (1);
	}
	print_base(base);
	free(base->space);
	free(base);
	return (0);
}

int	main(int ac, char **av)
{
	FILE	*config;
	int	ret;

	if (ac != 2)
	{
		ft_write("Error: argumrnt\n");
		return (1);
	}
	config = fopen(av[1], "r");
	if (config == NULL)
	{
		ft_write("Error: Operation file corrupted00\n");
		return (1);
	}
	ret = 0;
	ret = start_parsing(config);
	if (ret == 1)
	{
		ft_write("Error: Operation file corrupted\n");
		return (1);
	}
	fclose(config);
	return (0);
}
