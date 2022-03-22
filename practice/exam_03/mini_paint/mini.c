#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

typedef	struct	s_screen {

	int	width;
	int	height;
	char	back_char;
	char	*space;

}		t_screen;

typedef struct	s_circle {

	char	empty_char;
	float	xc;
	float	yc;
	float	radius;
	char	draw_char;

}		t_circle;

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


int	check_circle_params(t_circle *circle)
{
	if (circle->empty_char != 'c' && circle->empty_char != 'C')
		return (1);
	if (circle->xc < 0 || circle->yc < 0 || circle->radius < 0)
		return (1);
	return (0);
}

int	check_point(float x, float y, t_circle *circle)
{
	float	distance;
	float	diff;
	float	dis_x;
	float	dis_y;

	//(X, Y) (XC, YC)
	// Sqrt((x - xc) (x - xc) + (y - yc) * (y - yc))
	
	dis_x = (x - circle->xc);
	dis_x = dis_x * dis_x;
	dis_y = (y - circle->yc);
	dis_y = dis_y * dis_y;
	
	distance = sqrtf(dis_x + dis_y);
	diff = distance - circle->radius;
	if (diff <= 0.00000000)
	{
		if (diff <= -1.00000000)
			return (2);
		return(1);
	}
	return (0);
}

void	update_screen(t_screen *base, t_circle *circle)
{
	int	i;
	int	j;
	int	ret;
	int 	temp;

	i = 0;
	ret = 0;
	temp = 0;
	while(i < base->width)
	{
		j = 0;
		while(j < base->height)
		{
			ret = check_point((float)i, (float)j, circle);
			if (ret == 1)
			{
				temp = (base->width * j) + i;
				base->space[temp] = circle->draw_char;		
			}
			else if (ret == 2 && circle->empty_char == 'C')
			{
				temp = (base->width * j) + i;
				base->space[temp] = circle->draw_char;
			}
			j++;
		}
		i++;
	}
}

int	get_circles(FILE *config, t_screen *base)
{
	int		ret;
	t_circle	circle;
	int		i;

	ret = fscanf(config, "%c %f %f %f %c\n", &circle.empty_char, &circle.xc, &circle.yc, &circle.radius, &circle.draw_char);
	if (ret != 5)
		return (1);
	i = 0;
	while(ret == 5)
	{
		printf("empty [%c] x [%f] y [%f] radius [%f] draw_char [%c]\n", circle.empty_char, circle.xc, circle.yc, circle.radius, circle.draw_char);
		i = check_circle_params(&circle);
		if (i == 1)
			return (1);
		update_screen(base, &circle);
		ret = fscanf(config, "%c %f %f %f %c\n", &circle.empty_char, &circle.xc, &circle.yc, &circle.radius, &circle.draw_char);
	}
	printf("ret is %d\n", ret);
	if (ret != -1)
		return (1);
	return (0);
}

int	start_parse(FILE *config)
{
	t_screen	*base;
	int		ret;
	int		i;

	base = (t_screen *)malloc(sizeof(t_screen));
	if (base == NULL)
		return (1);
	ret = fscanf(config, "%d %d %c\n", &base->width, &base->height, &base->back_char);
	printf("width [%d] height [%d] char_back [%c]\n", base->width, base->height, base->back_char);
	if (ret != 3 || base->width < 0 || base->width > 300 || base->height < 0 || base->height > 300)
	{
		free(base);
		return (1);
	}
	ret = (base->width * base->height);
	base->space = (char *)malloc(sizeof(char) * (ret + 1));
	if (base->space == NULL)
	{
		free(base);
		return (1);
	}
	i = 0;
	while (i < ret)
	{
		base->space[i] = base->back_char;
		i++;
	}
	base->space[ret] = '\0';

	ret = get_circles(config, base);
	print_base(base);
	free(base->space);
	free(base);
	if (ret == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	FILE	*config;
	int	ret;

	if (ac != 2)
	{
		ft_write("Error: wrong args\n");
		return (1);
	}
	config = fopen(av[1], "r");
	if (config == NULL)
	{
		ft_write("Error: opening the file\n");
		return (1);
	}
	ret = 0;
	ret = start_parse(config);
	if (ret == 1)
	{
		ft_write("Error: wrong configutation in file\n");
		return (1);
	}
	return (0);
}
