// #include "../minishell.h"
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
// Одинаковые ошибки у unset/export
    argv[0] == "unset";  // // lisa.tokens[1]
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
   // OKEY
    if (!(argv[1]))
        // ничего // все ок
    if (argv[1]) 
    {
		if(ft_isalpha(*argv[1]) != 1 || strchr(argv[1], 61) == NULL) 
			printf ("ошибулечка, нам нужна только буква и строка без '=' \n");
	// 1 // printf("Monolisa: export: '%s': not a valid identifier\n", arr[1]);    
	// 2 // printf("Monolisa: syntax error near unexpected token 'newline'", arr[1]);  // (
	// 3 // printf(("Monolisa: syntax error near unexpected token '%s'", arr[1]);  // )
    
    // Сравниваем и ищем такое значение в env, если не находим, не меняем, находим -> меняем
		int i = 0;
        int size = 0;
        size = ft_strlen(argv[1]);
        while(env[i])
        {
            if(strncmp(argv[1], env[i], size) == 0)
            {
                env[i] = NULL; //типо удалила
            }
		    i++;
		}
	}
}
   
   



