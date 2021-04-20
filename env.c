#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>


char    *dif_str(char **my_env, char **env)
{
    int i;
	int tmp_i;
    i = 0;

    char *dif_s;

    while(env[i]) // пока env существует
    {
        printf("1 end my_env  %s\n", my_env[i]);
        printf("1 end env     %s\n", env[i]);
        if(strcmp(env[i], my_env[i]) == 0)
        {
            printf("разницы нет\n");
        }
        else if (strcmp(env[i], my_env[i]) != 0)
        {
            printf("\n\033[31mВот она разница, нашлася!\033[0m\n");
            dif_s = env[i];
			tmp_i = i; //запомню положение изменения (цифру)
			printf("\033[36m Положение разной строки : %d\033[0m\n\n", tmp_i);
            printf("\033[36m diff_s : %s\033[0m\n\n", dif_s);
			printf("getenv(имя переменнной) -> %s\n", getenv("LOGNAME"));
			printf("getenv(имя переменнной) -> %s\n", getenv("USER"));
        }
		i++;
    }
    return (dif_s);
}


void ft_env(char **my_env, char **env)
{
    int i;
    char *str;
    int fl_e;

    fl_e = 0;
    int ip;

// ДЛЯ Получение значения переменной окружения
// Посмотрим как работает /getenv/
    str = getenv("ZSH"); // кладу в *str 
    printf("Полученное значение - %s\n", str); // получаю значение ZSH

// для ИЗМЕНЕНИЯ ПЕРЕМЕННОЙ
// меняю переменную среды на arina
// TMPDIR=/var/folders/zz/zyxvpxvq6csfxvn_n0001rgr000f3y/T/
    printf("1/Изначально - %s\n", env[5]);
    putenv("LOGNAME=arina"); 
    printf("2/Измененное - %s\n", env[5]);

    while(env[i])
    {
        if(strcmp(env[i], my_env[i]) == 0)
        {
            // printf(" :) Переменная среды не поменялась\n");
        }
        else
        {
            printf("\n\033[31mATTENTION \033[0m\nОБНАРУЖИЛА ОШИБКУ\n\n");
            printf(" ;( Переменная среды  поменялась\n");
            printf("\n\n\033[35mCкореее пойдем искать с Викой измененную строку!\033[0m\n\n");
            dif_str(my_env, env);
        }
        i++;
    }
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
    ft_env(my_env, env);
    return (0);
}


