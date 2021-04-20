#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

void dif_str(char **my_env, char **env)
{
    int i;
    i = 0;

    char *dif_s;

    while(env[i]) // пока env существует
    {
        if(env[i] == my_env[i])
            i++;
        else
        {
            dif_s = env[i];
            i++;
        }
    }
}

void ft_env(char **my_env, char **env)
{
    char *name_env;
    char *tmp_name;
    
    while (env[i])
    {
        if (env[i])

        i++;
    }


    name_env = getenv(tmp_name);
}

int main(int argc, char **argv, char **env)
{
    char **my_env;
    int i;

    my_env = (char **)malloc(sizeof(char *) * ft_lenmassive(env) + 1);
    my_env[ft_lenmassive(env)] = NULL;
    i = -1;
    while (env[++i])
    my_env[i] = ft_strdup(env[i]);
    ft_env(my_env, env);


}


