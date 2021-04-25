#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

void some_parameters(char **argv)
{
	int fl = 0;
	// else if  (несколько добавлений / изменений)
	if(argv[2] && ft_isalpha(*argv[2]) != 0)
	{
		while(*argv[i] != '=' && *argv[i] != '=') //  *argv[1] // *argv[2]
		{
			if (*argv[i] == *argv[i])
			{
				i++;
			}
			else
				fl = 1;
		}
		if (fl == 0) //одинаковые строки -> перезапишем предыдущую
		{
			putenv();
		}
		if (strchr)
		if(strcmp(argv[2], argv[1]) == 0 || )
			printf ("Одинаковые переменные, ничего не доабвляем и не меняем\n");
		else if(strcmp(argv[2], argv[1]) != 0)
		{
			if
		}
	}
}

void sort_env(char **my_env)
{
	int		i = 0;
    int		s_i = 0;
	char	*temp;
    int     len = 0;

   
    printf("- %s -\n", my_env[i]);
    printf("- %s -\n", my_env[2]);

    while (my_env[len])
        len++;
    // printf("- %s -\n", my_env[len]);
    // printf("-i- %i -\n", len);
    while(i < len - 1)
    {
        s_i = 0;
        while(s_i < len -1)
        {
            if(strcmp(my_env[s_i],my_env[s_i + 1]) > 0)
            {
                temp = my_env[s_i + 1];
                my_env[s_i + 1] = my_env[s_i];
                my_env[s_i] = temp;

            }
            s_i++;
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

// my_env[i] = lisa.tokens[1] // одинаково

    int i;

    my_env = (char **)malloc(sizeof(char *) * ft_lenmassive(env) + 1);
    my_env[ft_lenmassive(env)] = NULL;
    i = -1;
    while (env[++i])
    my_env[i] = ft_strdup(env[i]);

	argv[0] == "export";  // // lisa.tokens[1]
    // argv[1] = "pilk" 
//  (цифра после переменной подает ( ошибки , тк все перемнные начинаются с букв))
    argv[1] = "5";  // err ошибка 1
    argv[1] = "="; // err ошибка 1
	argv[1] = "("; // err ошибка 2 
	argv[1] = ")";  // err ошибка 3
// 1 // printf("Monolisa: export: '%s': not a valid identifier\n", arr[1]);    
// 2 // printf("Monolisa: syntax error near unexpected token 'newline'", arr[1]);  // (
// 3 // printf(("Monolisa: syntax error near unexpected token '%s'", arr[1]);    // )
    argv[1] = "vik";
    int len = 0;
	if (!(argv[1])) // только export
	{
		// сортирвока по алфавиту "declare -x "
		ft_sort_ex(my_env);
	}
    if (argv[1]) // существует 2 аргумент для export // не цифра и не символ
    {
		if(ft_isalpha(*argv[1]) == 0) // *lisa.tokens[i] // *my_env[]
			printf ("ошибулечка, нам нужна только буква\n");
	// 1 // printf("Monolisa: export: '%s': not a valid identifier\n", arr[1]);    
	// 2 // printf("Monolisa: syntax error near unexpected token 'newline'", arr[1]);  // (
	// 3 // printf(("Monolisa: syntax error near unexpected token '%s'", arr[1]);  // )
		if (strchr(argv[1], 61) != NULL) // 61 в ascii "="
		{

		}
		else if (strchr(argv[1], 61) == NULL) // не нашел "="  //name/=/var   1/2/3
		{
			printf ("добавляем переменную *= , которая ничему не равна или равна\n");
			putenv(argv[1]);
			// но просто ничего не добавляем
			//может быть много равно, все обработаем , все ок
		}
	}
	// else if  (несколько добавлений / изменений)
	void some_parameters(argv);

			
	
	//(ошибка во втором аргументе)
	{
		printf ("Добавим первую, а вторая с ошибкой вылетает\n");
		putenv(argv[1]);
	// 1 // printf("Monolisa: export: '%s': not a valid identifier\n", arr[1]); 
	}

	return (0);
}
//isalnum (ищет цифры/буквы )
//isdigit (цифры)
//isalpha (буквы)
