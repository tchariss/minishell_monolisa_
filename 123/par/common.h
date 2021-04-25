#ifndef __MINISH_H__
#define __MINISH_H__

#define ERROR		(-1)
#define BADFD		(-2)

#define MAXFNAME	10
#define MAXARG		10
#define MAXWORD		20
#define MAXFD		20
#define MAXVAR		50
#define MAXNAME		20

#define TRUE		1
#define FALSE		0

#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int BOOLEAN;

// ������ Ÿ���� �����ϴ� ������ ����
typedef enum
{
	S_WORD,
	S_BAR,
	S_AMP,
	S_SEMI,
	S_GT,
	S_GTGT,
	S_LT,
	S_NL,
	S_EOF
} SYMBOL;

void syserr(char *message);
void redirect(int sourcefd, char *sourcefile, int destfd, char *destfile, BOOLEAN append, BOOLEAN backgrnd);
BOOLEAN shellcmd(int ac, char *av[], int sourcefd, int destfd);
SYMBOL getsymbol(char *word);
int execute(int ac, char *av[], int sourcefd, char *sourcefile, int destfd, char *destfile,
BOOLEAN append, BOOLEAN backgrnd);
void fatal(char *message);
void waitfor(int pid);
void print_prompt();
void cmd_cd(int ac, char *av[]);
int check_arg(char *av[], char *opt);
void cmd_exit();
void cmd_ls(int ac, char *av[]);
void cmd_cp(int ac, char *av[]);
void cmd_rm(int ac, char *av[]);
void cmd_mv(int ac, char *av[]);
void cmd_mkdir(int ac, char *av[]);
void cmd_rmdir(int ac, char *av[]);
void cmd_cat(int ac, char *av[]);
SYMBOL parse(int *waitpid, BOOLEAN makepipe, int *pipefdp);


#endif
