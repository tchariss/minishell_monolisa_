#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv, char **env)
{
    struct dirent *planet = NULL;
// 1
printf("\n/1/\n");
    // char *pack = "cdsdafs";

    // DIR *dir = opendir(pack);
    // if (dir == NULL)
    // {
    //     printf("не получилось у нас открыть, ошибулечка\n");
    //     exit (0);
    // }
    char *no_p = "check";  // такая папка существует !
    DIR *dir_2 = opendir(no_p);
    if (dir_2 == NULL)
    {
        printf("2 - не получилось у нас открыть, ошибулечка\n");
    }
    else
        printf("Привет дорогая папка |%s|, сейчас мы заглянем в тебя\n", no_p);
// 2
printf("\n/2/\n");

    while((planet = readdir(dir_2)) != NULL)
    {
        if (strcmp(planet->d_name, ".") == 0)
        { //уберем ненужные точечки внутри
            continue;
        }
        if (strcmp(planet->d_name, "..") == 0)
        {
            continue;
        }
        printf("%s \n", planet->d_name); //  выводит все имена файлов в папке
    }
    closedir(dir_2);
// 3
printf("\n/3/\n");
    // char *hmv = getenv("HOME");
    // printf("\n  Получили |%s| со значениями: |%s|\n", "HOME",hmv);
    // int ret = chdir(hmv);
    // printf("  chdir returned  : %d\n\n", ret);
    // printf("pwd : %s", getcwd(NULL, 0));
    // printf("chdir returned  : %d\n\n", chdir("./check"));

    char **arr;
    arr = (char **)malloc(sizeof(char **));
    arr[0] = "cd";
    // arr[1] = " ";
    arr[1] = ".";
    // arr[1] = "check"; //такая папка есть
    // arr[2] = "koyuravo"; // такой папки нет 

    if(strcmp(arr[0], "cd") == 0 && strcmp(arr[1], " ") != 0 && strcmp(arr[1], ".") != 0)
    {
        if(chdir(arr[1]) == 0) // (chdir) Возвр. знач : в случае успеха возвращается 0
        {
            printf("1 - Папка %s существует, уепии!\n", arr[1]);
            perror("cd");

        }
        if(chdir(arr[2]) < 0) // (chdir) При ошибке вернет -1
        {
            printf("2 - Папки  %s  нет у меня !\n", arr[2]);
            printf("Monolisa: cd: %s: No such file or directory\n", arr[2]);
            perror("cd");
        }
    }
    // else if (strcmp(arr[1], ".") == 0)
    //             (остаемся там, где и были)
    else // cd без параметров вернет на к "HOME"
    {
        ft_putstr_fd(getenv("HOME"), 1); 
    }

// 4
printf("\n/4/\n");
    char *pa_1 = "check"; //существующая папка
    char *pa_2 = "bulyon"; // нет такой папки
    if(chdir(pa_2) < 0)
		printf("- У нет тут такой папки : |%s| куда ты собрался\n", pa_2);
    if (opendir(pa_1) == 0)
        printf("- Я нашел папочку : |%s|\n", pa_1);
    exit (0);
}


// if cd ../ (env -> 