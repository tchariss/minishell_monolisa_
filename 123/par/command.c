#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include "common.h"
#include <string.h>

////////////////////////////////////////////////////////////////////////
//  �ش����ڰ� �����ϴ� Ȯ���ϴ� �Լ�
////////////////////////////////////////////////////////////////////////
int check_arg(char **av, char *opt)
{
	int count = 0;

	// ��� ���ڰ��� Ȯ���Ѵ�.
	while(*av)
	{
		// opt ���ڰ� �����ϴ°�?
		if(strcmp(av[count], opt) == 0)
		{
			return TRUE;
		}

		av++;
	}

	return FALSE;
}

////////////////////////////////////////////////////////////////////////
//  ���丮�� �����ϴ� �Լ�
////////////////////////////////////////////////////////////////////////
void cmd_cd(int ac, char *av[])
{
	char *path;

	// ���ڰ� ���� ��� path�� ����
	if(ac > 1)
	{
		path = av[1];
	}
	
	// ���ڰ� ���� ��� HOME���丮�� ����
	else if((path = (char*)getenv("HOME")) == NULL)
	{
		// ȯ�� ������ ���� ��� ���� ���丮�� ����
		path = ".";
	}

	// ���丮�� �����Ѵ�.
	if(chdir(path) == ERROR)
	{
		fprintf(stderr, "%s: bad directory.\n", path);
	}
}

////////////////////////////////////////////////////////////////////////
//  ���α׷��� ����
////////////////////////////////////////////////////////////////////////
void cmd_exit()
{
	exit(1);
}

////////////////////////////////////////////////////////////////////////
//  ���丮 ����Ʈ�� ����ϴ� �Լ�
////////////////////////////////////////////////////////////////////////
void cmd_ls(int ac, char *av[])
{
	DIR *dp;
	struct dirent *entry;
	char *path;
	int count;
	int opt_a;
	int opt_l;

	// ���ڰ� ���� ��� �ڱ� �ڽ��� ���丮�� �����Ѵ�.
	if(ac < 2)
	{
		path = ".";
	}
	
	// ���ڰ� ���� ��� ����
	else
	{
		path = av[1];
	}

	// ���丮�� ����.
	if((dp = opendir(path)) == NULL)
	{
		fprintf(stderr, "Can't open directory: %s", av[1]);
		return;
	}

	// ������ ���ڵ��� �����ϴ��� Ȯ��
	opt_a = check_arg(av, "-a");
	opt_l = check_arg(av, "-l");

	count = 0;

	// �����̳� ���丮�� �о���δ�.
	while((entry = readdir(dp)) != NULL)
	{
		// -a �ɼ��� ���� ��� ���� ������ ǥ������ �ʴ´�.
		if(!opt_a)
		{
			if(entry->d_name[0] == '.')
			{
				continue;
			}
		}
		
		// ���
		printf("%s\t", entry->d_name);

		// -l �ɼ��� �����Ǿ����� ��� �ٸ��� �ѿ��Ҿ��� ����Ѵ�.
		if(opt_l)
		{
			printf("\n");
		}
		
		// ���ٿ� 3���� ����Ѵ�.
		else
		{
			if(count > 3)
			{
				printf("\n");
				count = 0;
			}
			else
			{
				count++;
			}
		}
	}

	// ���丮�� �ݴ´�.
	closedir(dp);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////
//  ������ �����ϴ� �Լ�
////////////////////////////////////////////////////////////////////////
void cmd_cp(int ac, char *av[])
{
	FILE *src;
	FILE *dst;
	char ch;

	// ���ڰ� 2�� ������ ��� ����
	if(ac < 3)
	{
		fprintf(stderr, "Not enough arguments.\n");
		return;
	}

	// ������ �ҽ� ������ ����.
	if((src = fopen(av[1], "r")) == NULL)
	{
		fprintf(stderr, "%s: Can't open file.\n", av[1]);
		return;
	}

	// ���⸦ �� ������ ����.
	if((dst = fopen(av[2], "w")) == NULL)
	{
		fprintf(stderr, "%s: Can't open file.\n", av[2]);
		return;
	}

	// ����
	while(!feof(src))
	{
		ch = (char) fgetc(src);

		if(ch != EOF)
		{
			fputc((int)ch, dst);
		}
	}

	// -v �ɼ��� ���� ��� ���� ���
	if(check_arg(av, "-v"))
	{
		printf("cp %s %s\n", av[1], av[2]);
	}

	fclose(src);
	fclose(dst);
}

////////////////////////////////////////////////////////////////////////
//  ���� ���� ���� �Լ�
////////////////////////////////////////////////////////////////////////
void cmd_rm(int ac, char *av[])
{
	// ���ڰ� ���� ��� ����
	if(ac < 2)
	{
		fprintf(stderr, "Not enough arguments.\n");
		return;
	}

	// ���� ����
	unlink(av[1]);

	// -v �ɼ��� ���� ��� ��� ���
	if(check_arg(av, "-v"))
	{
		printf("rm %s\n", av[1]);
	}
}

////////////////////////////////////////////////////////////////////////
//  ����  �̵� ���ɾ�
////////////////////////////////////////////////////////////////////////
void cmd_mv(int ac, char *av[])
{
	FILE *src;
	FILE *dst;
	char ch;

	// ���ڰ� 2�� ������ ��� ����
	if(ac < 3)
	{
		fprintf(stderr, "Not enough arguments.\n");
		return;
	}

	// ������ ������ ����.
	if((src = fopen(av[1], "r")) == NULL)
	{
		fprintf(stderr, "%s: Can't open file.\n", av[1]);
		return;
	}

	// ������ ������ ����.
	if((dst = fopen(av[2], "w")) == NULL)
	{
		fprintf(stderr, "%s: Can't open file.\n", av[2]);
		return;
	}

	// ����
	while(!feof(src))
	{
		ch = (char) fgetc(src);

		if(ch != EOF)
		{
			fputc((int)ch, dst);
		}
	}

	fclose(src);
	fclose(dst);

	// ���� ���� ����
	unlink(av[1]);

	// -v �ɼ��� ����ϸ�  ����� ����Ѵ�.
	if(check_arg(av, "-v"))
	{
		printf("mv %s %s\n", av[1], av[2]);
	}
}

////////////////////////////////////////////////////////////////////////
//  ���丮�� �����ϴ� �Լ�
////////////////////////////////////////////////////////////////////////
void cmd_mkdir(int ac, char *av[])
{
	// ���ڰ� ���� ��� ����
	if(ac < 2)
	{
		fprintf(stderr, "Not enough arguments.\n");
		return;
	}

	// ���丮�� �����Ѵ�.
	// if(dir(av[1], 0755))
	// {
	// 	fprintf(stderr, "Make directory failed.\n");
	// }
}

////////////////////////////////////////////////////////////////////////
//  ���丮�� �����ϴ� �Լ�
////////////////////////////////////////////////////////////////////////
void cmd_rmdir(int ac, char *av[])
{
	// ���ڰ� ���� ��� ����
	if(ac < 2)
	{
		fprintf(stderr, "Not enough arguments.\n");
		return;
	}

	// ���丮�� �����Ѵ�.
	if(rmdir(av[1]))
	{
		fprintf(stderr, "Remove directory failed.\n");
	}
}

////////////////////////////////////////////////////////////////////////
//  cat ���ɾ� �Լ�
////////////////////////////////////////////////////////////////////////
void cmd_cat(int ac, char *av[])
{
	int ch;
	FILE *fp;

	// ���ڰ� ���� ��� ����ó��
	if(ac < 2)
	{
		fprintf(stderr, "Not enough arguments");
		return;
	}

	// �ϱ��������� ������ ����.
	if((fp = fopen(av[1], "r")) == NULL)
	{
		fprintf(stderr, "No such file on directory.\n");
		return;
	}

	// ���� ���
	while((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}

	fclose(fp);
}
