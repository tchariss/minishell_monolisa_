
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
# include <curses.h>
# include <term.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"

void sort_env(char **str_array)
{
	int		i = 0;
    int		s_i = 0;
	char	*temp;
    int     len = 0;

   
    printf("- %s -\n", str_array[i]);
    printf("- %s -\n", str_array[2]);

    while (str_array[len])
        len++;
    // printf("- %s -\n", str_array[len]);
    // printf("-i- %i -\n", len);
    while(i < len - 1)
    {
        s_i = 0;
        while(s_i < len -1)
        {
            if(strcmp(str_array[s_i],str_array[s_i + 1]) > 0)
            {
                temp = str_array[s_i + 1];
                str_array[s_i + 1] = str_array[s_i];
                str_array[s_i] = temp;

            }
            s_i++;
        }
        i++;
    }
  
	// while (str_array[i])
	// {
	// 	// i = 0;
    //     printf("ЦИКЛi-s_env_len- %i -\n", s_env_len);
    //     printf("ЦИКЛ i-- %i -\n", i);
	// 	while (i < s_env_len - 1)
	// 	{
    //         printf("213456543");
	// 		if (strcmp(str_array[i], str_array[i + 1]) > 0)
	// 		{
	// 			temp = str_array[i];
	// 			str_array[i] = str_array[i + 1];
	// 			str_array[i + 1] = temp;
    //             printf("213456543");
	// 		}
	// 		i++;
	// 	}
	// 	// i++;
    // }
}

void	free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

int main(int argc, char **argv, char **env)
{
    char **str_array;
    str_array = (char **)malloc(sizeof(char *) * 5 + 1);
    str_array[5] = NULL;
    // int a = -1;
    // while (str_array[++a])
    // str_array[i] = ft_strdup(env[a]);

    str_array[0] = "DESS";
    str_array[1] = "LOGNAME=tchariss";
    str_array[2] = "AHLVL=2";
    str_array[3] = "1PAGER=less";
    str_array[4] = "./BAGER=less";
    
    char *s1 = "LOGNAME";
    // массив из 30-ти строк
    // каждая из 79 символов включительно
    int size = 0;
    int i = 0;
    int a = 0;
    int sort = 1;
    // while (str_array[i]) 
    // {
    // printf("|%d|\n", strcmp("\200","\0"));
    if (sort == 1)
    {   
        printf("До\n");
        while(str_array[a])
        {
            printf("|%s|\n", str_array[a]);
            a++;
        }
        sort_env(str_array);
        printf("После\n");
        size = ft_strlen(s1);
        while(str_array[i])
        {
            if (strncmp(s1, str_array[i], size) == 0) // если нашли такую же строчку
            {
                printf("\n!!!\nМы нашли такую же строчку, вот она -> |%s| А вот наша ! -> |%s|\n", str_array[i], s1);
                // ft_bzero(str_array[i], ft_strlen(str_array[i]));
                str_array[i] = NULL;
            }
            // printf("|%s|\n", str_array[i]);
            i++;
        }

        int e = 0;
        while(str_array[e])
        {
            printf("|||||%s|\n", str_array[e]);
            e++;
        }
    }
    //     printf ("Строка номер |%i|, органы строки -> |%s|\n\n", i, str_array[i]);
	// 	if(ft_isalpha(*str_array[i]) != 1)  // если не буква
	// 	{
    //     	printf ("Ошибулечка, символ |%c| не принимаем, нужна буква и строка без '='\n", *str_array[i]);
    //     }
    //     if ((strchr(str_array[i], 61)) == NULL) //  если не нашли равно
    //     {
    //         printf("В строке |%s| нет равно спросим у strchr -> |%s|\n", str_array[i], strchr(str_array[i], 61));
    //     }
   
    //     else
    //     {
    //         // printf(" :(((Не нашли мы строчку такую -> |%s|\n\n", s1); // не нашли ;(((
    //     }
    //     i++;
    return (0);
    // }
}

	// 1 // printf("Monolisa: export: '%s': not a valid identifier\n", arr[1]);    
	// 2 // printf("Monolisa: syntax error near unexpected token 'newline'", arr[1]);  // (
	// 3 // printf(("Monolisa: syntax error near unexpected token '%s'", arr[1]);  // )

    // Сравниваем и ищем такое значение в env, если не находим, не меняем, находим -> меняем
		// if (strchr(str_array[1], 61) != NULL) // 61 в ascii "="
		// {
        //     // printf ("ошибулечка, нам нужна только буква и название без  '=' \n");
		// }
		// else if (strchr(str_array[1], 61) == NULL) // не нашел "="  //name/=/var   1/2/3
		// {
		// 	printf ("добавляем переменную *= , которая ничему не равна или равна\n");
		// 	putenv(str_array[1]);
		// 	// но просто ничего не добавляем
		// 	//может быть много равно, все обработаем , все ок
		// }

    // // int a = 0;
    // // int j;
    // char *s = "abc0eeeeef";
    // // char *s2 = "abcflop";
    // printf("\n\034 i - %s\033[0m\n", strchr(argv[1], 61));
    // while(str_array[i])
    // {
    // //     // printf("\nstr - |%s|\n", s);
    // //     // printf("c - |%c|\n", *s);
    // //     // printf("i ++ - |%i|\n", *s[a++]);

    // //     // printf("\n\034 argv - |%s| \033[0m\n", argv);
    // //     printf("\n\034 **argv (символ) - %c\033[0m\n", *argv[i]);
    // //     printf("\n\034 **argv (символ) - %c\033[0m\n", **argv);
    //     printf("\n\034 str_array[i] - |%s| \033[0m\n", str_array[i]);
    // //     printf("\n\034 i - |%i|\033[0m\n", i);
    // //     printf("\n\034 *argv[i] - %c\033[0m\n", *argv[0]);
    // //     // printf("\n\034 *argv[i] - %c\033[0m\n", *argv[1][1]);
    // //     // printf("\n\034 адинаковыеее символыыы - %i\033[0m\n", i);
    // //     // j++;
    //     i++;
    // }
        
    // while(s1[i]) // пока env существует
    // {
        // if(strcmp(s1, s2) == 0)
        // {
        //     printf("разницы нет\n");
        // }
        // else if (strcmp(s1, s2) != 0)
        // {
        //     printf("\n\033[31mВот она разница, нашлася!\033[0m\n");
        //     dif_s = s1[i];
		// 	tmp_i = strcmp(s1, s2); //запомню положение изменения (цифру)
		// 	printf("\033[36m Положение разной строки : %d\033[0m\n\n", tmp_i);
        //     printf("\033[36m diff_s : %c\033[0m\n\n", dif_s);
        // }
        // s_dif = strstr(s1, s2);
        // printf("\033[32m sym_s : %s\033[0m\n\n", strchr(s1, 61));
        // printf("\033[35m sym_s : %s\033[0m\n\n", ft_strchr(s2, 61));
        // char *sp = strchr(s2, 61);

        // printf("\033[32m sym_s : %d\033[0m\n\n", strcmp(s1, s2));
        // // printf("\033[35m sym_s : %d\033[0m\n\n", strcmp(s2, 61));

        // printf("\033[32m striiiing with pos = : %c\033[0m\n\n", *--sp);
        // printf("\033[31m sym_s : %s\033[0m\n\n", strchr(s3, 61));
        // printf("\033[36m 1 - diff_s : %s\033[0m\n\n", strstr(s1, s2));
        // printf("\033[32m 2 - diff_s : %s\033[0m\n\n", strstr(s1, s3));
		// i++;
    // }
    // return (dif_s);
    // return (0);
    // printf("символ - |%c|\n", *my_env[1]);
    
// }