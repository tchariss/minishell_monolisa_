#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "common.h"

////////////////////////////////////////////////////////////////////////
//  ǥ�� ��/����� �̿��� �����̷�Ʈ �Լ�
////////////////////////////////////////////////////////////////////////
void redirect(int sourcefd, char *sourcefile, int destfd, char *destfile, BOOLEAN append, BOOLEAN backgrnd)
{
	int flags, fd;

	// �����ִ� �ҽ� ���ϵ�ũ���Ͱ� ���� ��׶��� ������ ���
	if (sourcefd == 0 && backgrnd) 
	{
		strcpy(sourcefile, "/dev/null");
		sourcefd = BADFD;
	}

	// �ҽ� ���� ��ũ���Ͱ� ���� ���
	if (sourcefd != 0) 
	{
		// ǥ���Է��� �ݴ´�.
		if (close(0) == ERROR)
		{
			syserr("close");
		}

		if (sourcefd > 0) 
		{
			// ǥ���Է��� �������Ѵ�.
			if (dup(sourcefd) != 0)
			{
				fatal("dup");
			}
		}

		// �ҽ������� ����.
		else if (open(sourcefile, O_RDONLY, 0) == ERROR)
		{
			fprintf(stderr, "Cannot open %s\n", sourcefile);
			exit(0);
		}
	}
   
	// ��� ���� ��ũ���Ͱ� �ִٸ�
	if (destfd != 1) 
	{
		// ǥ�� ����� �ݴ´�.
		if (close(1) == ERROR)
		{
			syserr("close");
		}

		// ǥ�� ����� ������
		if (destfd > 1) 
		{
			if (dup(destfd) != 1)
			{
				fatal("dup");
			}
		}

		else
		{
			// ������ ���� ��쿡 �����ϰ�, ���⵵ �����ϰ� ������ ����
			flags = O_WRONLY | O_CREAT;
			
			// �߰� ��尡 �ƴ� ��� ������ ���� �ɼǵ� �߰�
			if (!append)
			{
				flags |= O_TRUNC;
			}

			// ������ ����.
			if (open(destfile, flags, 0666) == ERROR) 
			{
				fprintf(stderr, "Cannot create %s\n", destfile);
				exit(0);
			}

			// �߰� ����� ���� ���� ã�´�.
			if (append)	
			{
				if (lseek(1, 0L, 2) == ERROR) syserr("lseek");
			}
		}
	}

	// ���ϵ�ũ���͸� �ݴ´�.
	for (fd =3; fd < MAXFD; fd++)
	{
		close(fd);
	}

	return;
}
