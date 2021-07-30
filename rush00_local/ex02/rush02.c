#include <unistd.h>

void    ft_putchar(char c);

void    error(int x, int y)
{
    if ((x == 0 || y == 0) || (x < 0 || y < 0))
    {
        write(1, "Digite novamente!", 17);
    }
}

void    rush(int x, int y)
{
    int    i;
    int    j;

    j = 1;
    error(x, y);
    while (j <= y)
    {
        i = 1;
        while (i <= x)
        {
            if ((i == 1 && j == 1) || (i == x && j == 1))
                ft_putchar('A');
            else if ((i == 1 && j == y) || (i == x && j == y))
                ft_putchar('C');
            else if (i == 1 || j == 1 || i == x || j == y)
                ft_putchar('B');
            else
                ft_putchar(' ');
            i++;
        }
        j++;
        write(1, "\n", 1);
    }    
}  
