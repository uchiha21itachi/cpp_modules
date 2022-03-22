#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_data {

    int     width;
    int     height;
    char    back;
    float   X;
    float   Y;

}               t_data;

typedef struct  s_rect {

    char        back_char;
    float       xr;
    float       yr;
    float       w;
    float       h;

}               t_rect;

void    ft_write(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int     check_point(int x, int y, t_rect rect)
{
    float     x1r, y1r;

    (void)x;
    (void)y;
    x1r = rect.xr + (float)rect.w;     //bottom right x1
    y1r = rect.yr + (float)rect.h;

    printf("top left x[%f] y[%f] bott right [%f] [%f]\n", rect.xr, rect.yr, x1r, y1r);
    return (0);
}

void    draw_rectangle(t_data data, t_rect rect)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    (void)rect;
    while(j <= data.height)
    {
        while(i <= data.width)
        {
            if (check_point(j, i, rect) == 1)
            {
                write(1, &rect.back_char, 1);
            }
            write(1, &data.back, 1);
            i++;
        }
        write(1, "\n", 1);
        i = 0;
        j++;
    }
}

void    parse(FILE *config)
{
    int     i;
    t_data  data;
    t_rect  rect;
    char    c;

    data.width = -1;
    data.height = -1;
    i = fscanf(config, "%d %d %c\n", &data.width, &data.height, &data.back);
    if (i != 3)
    {
        printf("error in scanning draw info\n");
        return ;
    }
    printf("width [%d] height [%d] char [%c]\n", data.width, data.height, data.back);
    printf("i is %d\n",i);
    i = 0;
    i = fscanf(config, "%c %f %f %f %f %c\n", &c, &rect.xr, &rect.yr, &rect.w, &rect.h, &rect.back_char);
    while(i == 6)
    {
        printf("char %c x [%f] y[%f] width [%f] height [%f] back char [%c]\n", c, rect.xr, rect.yr, rect.w, rect.h, rect.back_char);
        i = fscanf(config, "%c %f %f %f %f %c\n", &c, &rect.xr, &rect.yr, &rect.w, &rect.h, &rect.back_char);
    }
    printf("i in the end %d\n", i);
    draw_rectangle(data, rect);
}

int main(int ac, char **av)
{
    FILE    *config;

    if (ac != 2)
    {
        ft_write("Error: argument\n");
        return (1);
    }
    printf("path - %s\n", av[1]);
    config = fopen(av[1], "r");
    if (config == NULL)
    {
        ft_write("Error: opening the file\n");
        return (1);
    }
    parse(config);
    return (0);
}