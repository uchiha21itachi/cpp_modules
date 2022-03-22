#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

typedef struct  s_screen{

    int     width;
    int     height;
    char    back_char;
    char    *space;
}               t_screen;


typedef struct  s_circle{

    char    empty;
    float   xr;
    float   yr;
    float   radius;
    char    draw_char;

}               t_circle;



void    print_circle(t_screen *base)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (j < base->height)
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

int     check_if_in(float i, float j, t_circle *cir)
{
    float   dist1;
    float   dist2;
    float   total;
    float   diff;

    dist1 = (i - cir->xr);
    dist1 = dist1 * dist1;
    dist2 = (j - cir->yr);
    dist2 = dist2 * dist2;
    total = sqrtf(dist1 + dist2);

    diff = total - cir->radius;
    if (diff <= 0.00000000)
    {
        if (diff < -1.00000000)
            return (1);
        return (2);
    }
    return (0);
}

void    update_base(t_screen *base, t_circle *cir)
{
    int     ret;
    int     i;
    int     j;

    i = 0;
    j = 0;
    ret = 0;
    while (j < base->height)
    {
        i = 0;
        while(i < base->width)
        {
            ret = check_if_in((float)i, (float)j, cir);
            if (ret == 1 && cir->empty == 'C')
            {
                base->space[(base->width * j) + i] = cir->draw_char;
            }
            else if (ret == 2)
            {
                base->space[(base->width * j) + i] = cir->draw_char;
            }
            i++;
        }
        j++;
    }

}

int get_circle(FILE *config, t_screen *base)
{
    t_circle cir;
    int      ret;

    ret = fscanf(config, "%c %f %f %f %c\n", &cir.empty, &cir.xr, &cir.yr, &cir.radius, &cir.draw_char);
    while(ret == 5)
    {
        if (cir.empty != 'c' && cir.empty != 'C')
            return (1);
        if (cir.radius <= 0.00000000)
            return (1);
        update_base(base, &cir);
        ret = fscanf(config, "%c %f %f %f %c\n", &cir.empty, &cir.xr, &cir.yr, &cir.radius, &cir.draw_char);
    }
    if (ret != -1)
        return (1);
    return (0);
}

int start_parse(FILE *config)
{
    int         ret;
    t_screen    *base;
    int         size;
    int         i;

    base = (t_screen *)malloc(sizeof(t_screen));
    if (base == NULL)
        return (1);
    ret = fscanf(config, "%d %d %c\n", &base->width, &base->height, &base->back_char);
    if (ret != 3 || base->width < 0 || base->height < 0 || base->width > 300 || base->height > 300)
    {
        free(base);
        return (1);
    }
    size = base->height * base->width;
    base->space = (char *)malloc(sizeof(char) * (size + 1));
    if (base->space == NULL)
    {
        free(base);
        return (1);
    }
    i = 0;
    while (i < size)
    {
        base->space[i] = base->back_char;
        i++;
    }
    ret = 0;
    ret = get_circle(config, base);
    if (ret == 1)
    {
        free(base->space);
        free(base);
        return (1);
    }
    print_circle(base);
    free(base->space);
    free(base);
    return (0);
}

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

int main(int ac, char **av)
{
    FILE    *config;
    int     ret;

    if (ac != 2)
    {
        ft_write("Error: wrong arguments\n");
        return (1);
    }
    config = fopen(av[1], "r");
    if (config == NULL)
    {
        ft_write("Error: wrong config file\n");
        return(1);
    }
    ret = start_parse(config);
    fclose(config);
    if (ret == 1)
    {
        ft_write("Error: wrong config file\n");
        return (1);
    }
    // while(1);
    return (0);
}