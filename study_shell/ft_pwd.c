#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

char *ft_pwd(char *str)
{
    char *s1;

    s1 = getcwd(NULL, 0);
    strlcat(s1, "\n", ft_strlen(s1) + 2);
    return (s1);
}

int main(void)
{
    char *s;
    ft_putstr_fd(ft_pwd(s), 1);
}
