#include <stdlib.h>
#include <stdio.h>


int *first(int x)
{
    x++;
    printf("x is %d\n", x);
}

int     main(void)
{
    int a;
    int *b;

    a = 10;
    b = &a;
    printf("a is %d\n", a);
    printf("a  addr is %p\n", &a);
    printf("b is %d\n", *b);
    printf("b  have is %p\n", b);
    printf("b  addr is %p\n", &b);

    printf("calling the first func\n");
    b = first(a);
    return (0);
}