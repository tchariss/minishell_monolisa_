#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>

// **env

// env[0] - TMPDIR= 
// env[1] - SHELL=/bin/zsh
// env[2] - HOME=/Users/tchariss

// env[i] -  (ключ) = (значение)

int main(int argc, char **argv, char **env)
{
    int i;

    i = 0;
    printf("count argc(argument count): /%d/\n", argc);
    printf("argv name 1, 2, 3...:\n");
    for(i=0; i< argc; i++)
    {
        printf(" - /%d/ : %s\n", i, argv[i]);
    }
    // return 0;

    getenv(env[i]);
    printf("getenv - %s\n", getenv(env[i]));
    while(env[i])
    {
        printf("i = /%d/ -> %s\n",i, env[i]);
        i++;
    }
    return (0);
}
    // if(argc != 2)
    // {
    //     printf("Usage: %s <environment key> \n", argv[0]);
    //     return 1;
    // }
    // char *env = getenv(argv[1]);

    // if(env)
    // {
    //     printf("%s value is %s\n",argv[1], env);
    // }
    // else
    // {
    //     printf("%s is not existed\n",argv[1]);
    // }
    // return 0;


    // if(argc != 3)
    // {
    //     printf("Usage: %s <key> <value> \n",argv[0]);
    //     return 1;
    // }
 
    // char *env = getenv(argv[1]);
    // if(env)
    // {
    //     printf("old %s's key is %s\n",argv[1], env);
    //     setenv(argv[1], argv[2], 1);
    // }
    // else
    // {
    //     printf("%s's key is not existed\n", argv[1]);
    //     char buf[256]="";
    //     sprintf(buf, "%s=%s", argv[1], argv[2]);
    //     putenv(buf);
    // }
    // printf("after...\n");
    // env = getenv(argv[1]);
    // printf("%s's key is %s\n", argv[1], env);
    // return 0;
}
