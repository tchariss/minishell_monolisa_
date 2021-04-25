#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

////////////////////////////////////////////////////////////////////////
//  ��ɾ �Ľ��Ѵ�.
////////////////////////////////////////////////////////////////////////
SYMBOL parse(int *waitpid, BOOLEAN makepipe, int *pipefdp)
{
	SYMBOL symbol, term;
	int argc, sourcefd, destfd;
	int pid, pipefd[2];
	char *argv[MAXARG+1], sourcefile[MAXFNAME];
	char destfile[MAXFNAME];
	char word[MAXWORD];
	BOOLEAN append;

	argc = 0;			
	sourcefd = 0;		
	destfd = 1;			

	
	while (TRUE) 
	{
		// �ϳ��� �ܾ�� �м��Ѵ�.
		switch (symbol = getsymbol(word))		
		{
			// �Ϲ� ������ ���
			case S_WORD :					
				if(argc == MAXARG) 
				{
					fprintf(stderr, "Too many args.\n");
					break;
				}

				// ���ο� ���� �迭�� �޸� �Ҵ� �Ѵ�.
				argv[argc] = (char *) malloc(strlen(word)+1);
				
				if(argv[argc] == NULL) 
				{
					fprintf(stderr, "Out of arg memory.\n");
					break;
				}

				// ��ɾ� ����
				strcpy(argv[argc], word);
				
				// arg ī���� ����
				argc++;
				continue;

			// < �� ���
			case S_LT   : 
			
				// �������� �����ִٸ� ����
				if(makepipe) 
				{
					fprintf(stderr, "Extra <.\n");
					break;
				}

				// �ҽ������� �ɺ����� �˻��Ѵ�.
				if(getsymbol(sourcefile) != S_WORD) 
				{
					fprintf(stderr, "Illegal <.\n");
					break;
				}

				sourcefd = BADFD;
				continue;

			// > Ȥ�� >> �� ���
			case S_GT   :
			case S_GTGT :

				// ���� ������ ���ǵǾ����� ���� ��� ����
				if(destfd != 1) 
				{
					fprintf(stderr, "Extra > or >>.\n");
					break;
				}

				// ������ ������ �ɺ�Ÿ���� ���ڿ��� �ƴϸ� ����
				if(getsymbol(destfile) != S_WORD) 
				{
					fprintf(stderr, "Illegal > or >>.\n");
					break;
				}

				// GTGT�� ��� �߰� ����
				destfd = BADFD;
				append = (symbol == S_GTGT);
				continue;

			// |, &, ;, �ٹٲ� ������ ��� - �ϳ��� ��ɾ� ����
			case S_BAR  :
			case S_AMP  :
			case S_SEMI :
			case S_NL   :
			
				argv[argc] = NULL;
				// �ɺ��� ������(|) �� ���
				if(symbol == S_BAR) 
				{
					if(destfd != 1) 
					{
						fprintf(stderr, "> or >> conflicts with |.\n");
						break;
					}
					
					// ������ ǥ����� ��ũ���͸� �Բ� �Ѱ� ��ɾ �м��Ѵ�.
					term = parse(waitpid, TRUE, &destfd);
				}
				
				// ���� ���� ����
				else
				{
					term = symbol;
				}

				// �������� �������� ��� �������� �����Ѵ�.
				if (makepipe) 
				{
					if (pipe(pipefd) == ERROR)
					{
						syserr("pipe");
					}
					*pipefdp = pipefd[1];
					sourcefd = pipefd[0];
				}

				// ����� �����Ѵ�.
				pid = execute(argc, argv, sourcefd, sourcefile,
								destfd, destfile,append, term == S_AMP);

				// �������� �ƴ� ��� ��ٸ� PID�� ����
				if (symbol != S_BAR)
				{
					*waitpid = pid;
				}

				// ���ڰ��� ���� ���
				if (argc == 0 && (symbol != S_NL || sourcefd > 1))
				{
					fprintf(stderr, "Missing command.\n");
				}

				// ���ڷ� �Էµ� ������ �޸� ����
				while (--argc >= 0)
				{
					free(argv[argc]);
				}

				return term;

			// ����� �߸��Ǿ��� ��� ����
			case S_EOF : 
				exit(0);
		} 
	}    
}
