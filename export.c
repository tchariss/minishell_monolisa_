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