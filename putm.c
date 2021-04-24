#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

// {int main(int argc, char **argv, char **env)

//export
int main(int argc, char **argv,char **envp)
{
    // argv[1] = "pilk" 
    argv[1] = "5";  // err ошибка
    argv[1] = "="; // err ошибка
// printf("Monolisa: export: '%s': not a valid identifier\n", arr[1]);    
    argv[1] = "vik";
    if (!(argv[1]))
		// сортирвока по алфавиту "declare -x "
		ft_sort_ex(env, my_env);
    if (argv[1]) // существует 
    {

    }   
    if(argv[1] && if(argv[i++] != "=") //name/=/var   1/2/3
	{
		printf ("ошибулечка, потому ничего не меняем\n")
	}

    {
        printf("Usage: %s <key> <value> \n",argv[0]);
        return 1;
    }
 
    char *env = getenv(argv[1]);
    if(env)
    {
        printf("old %s's key is %s\n",argv[1], env);
        setenv(argv[1], argv[2], 1);
    }
    else
    {
        printf("%s's key is not existed\n", argv[1]);
        char buf[256]="";
        sprintf(buf, "%s=%s", argv[1], argv[2]);
        putenv(buf);
    }
    printf("after...\n");
    env = getenv(argv[1]);
    printf("%s's key is %s\n", argv[1], env);
    return 0;
}
