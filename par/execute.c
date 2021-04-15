#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

////////////////////////////////////////////////////////////////////////
//  ��ɾ �����ϴ� �Լ�
////////////////////////////////////////////////////////////////////////
int execute(int ac, char *av[], int sourcefd, char *sourcefile, int destfd, char *destfile,
	BOOLEAN append, BOOLEAN backgrnd)
{
	int pid;

	// ���ڰ� ���ų� ����� ���� ����� �����Ͽ� �����Ͽ��� ���
	if (ac == 0 || shellcmd(ac, av, sourcefd, destfd))
	{
		return 0;
	}

	// ���μ����� fork�Ѵ�.
	pid = fork();

	switch (pid)
	{
		// ������ ���� ���
		case ERROR : 
			fprintf(stderr, "Cannot create new process.\n");
			return 0;

		// �ڽ��϶�, ���α׷��� �����ϴ� ��ü
		case 0 :     
			redirect(sourcefd, sourcefile, destfd, destfile, append, backgrnd);
			execvp(av[0], av);
			fprintf(stderr, "Cannot execute %s\n", av[0]);
			exit(0);

		// �θ��� ��
		default :
			// �б� ���ϵ�ũ������ �ݴ´�.
			if(sourcefd > 0 && close(sourcefd) == ERROR)
			{
				syserr("close sourcefd");
			}

			// ���� ���ϵ�ũ������ �ݴ´�.
			if(destfd > 1 && close(destfd) == ERROR)
			{
				syserr("close destfd");
			}

			// ��׶��� ����� ��� pic ���
			if(backgrnd)
			{
				printf("%d\n", pid);
			}
			
			return pid;
	}
}
