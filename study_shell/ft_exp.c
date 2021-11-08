#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

int main(int argc, char **argv, char **env)
{
	argv[0] == "export";
    char *s;
    char *s1;
    char *s2;
    int i = 0;

	if(argv[i++] != "=")  //  /name/=/var   1/2/3
	{
		printf ("ошибулечка, потому ничего не меняем\n")
	}
	else if ( "=") // shell=1 2 (%s = 2)
	{
    	printf ("добавляем переменную *= , которая ничему не равна")
	}
	// else if  (несколько добавлений / изменений)
	// else if  (цифра после переменной подает ( ошибки , тк все перемнные начинаются с букв))
}
//isalnum (ищет цифры/буквы любого регистра)

void ft_sort_ex(char **env, char **my_env)
{
	
}

int ft_lenmassive(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
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
	argv[0] == "export";
	// argv[1] == " "; // 
	if (!(argv[1]))
		// сортирвока по алфавиту "declare -x "
		ft_sort_ex(env, my_env);
	else if (argv[1])


}
