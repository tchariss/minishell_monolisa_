#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

void sig_int()
{
    fprintf(stderr, "SIGINT !!!!\n");
    sleep(5);
}

int main(int argc, char **argv)
{
    int pid;
    int sig_num;

    if ((signal(SIGINT, sig_int)) == SIG_ERR)
    {
        perror("signal setting error : ");
        exit(1);
    }
    if (argc != 3)
    {
// pid: PID процесса
// sig: номер сигнала
        printf("usage %s [pid] [signum]\n", argv[0]);
        return 1;
    }

    pid = atoi(argv[1]);
    sig_num = atoi(argv[2]);
    // (kill) - Для передачи сигнала процессу
    if(!kill(pid, sig_num))
    {
        perror("Signal Send error");
        return 1;
    }
    return 0;
}