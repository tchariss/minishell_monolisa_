#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

char *ft_pwd(char *str, char **env)
{
    char *s1;

    s1 = getcwd(NULL, 0);
    strlcat(s1, "\n", ft_strlen(s1) + 2);
    return (s1);
}

void ft_echo(char **str, char **env)
{
    int i = 1;
    int fl_cmd = 0;
    char *str_name_env = "GIT_ASKPASS";

    if(strcmp("-n", str[1]) == 0)
        ft_putstr_fd(NULL, 1);
    else if(*str[1] == '$')
    {
        // ft_putstr_fd("$-tut", 1);
        // printf("s:%s\n", *str);
        // printf("s1:%s\n", str[i++]);
        // printf("c:%c\n", *str[i]);
        fl_cmd = 1;
        //// Ищем команды, которые есть в env и выводим их 
        // getenv -> Получает значения переменной окружения
        if (strcmp(str_name_env, "GIT_ASKPASS") == 0)
        {
            char *str_env = getenv("GIT_ASKPASS");
            printf("%s\n", str_env);
        }
        /////
        // 2 вариант
        if(strcmp("$PWD", str[i++]) == 0)
        {
            ft_putstr_fd(getcwd(NULL, 0), 1);
            ft_putstr_fd("\n", 1);
        }
    }
    else
    {
        ft_putstr_fd(str[1], 1);
        ft_putstr_fd("\n", 1);        
    }
}

int main(int argc, char **argv, char **env)
{
    char *ar[2];

    ar[0] = "echo";
    ar[1] =  "$PWD";

    ft_echo(ar, env);
}


////// echo for search NAME env
// Пример : echo $PWD
// /Users/tchariss/Desktop/minishell/liza
// Строка 26, см. выше
