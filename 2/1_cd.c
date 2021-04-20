void cmd_cd(int ac, char *av[])
{
	char *path;

	if(ac > 1)
	{
		path = av[1];
	}
	else if((path = (char*)getenv("HOME")) == NULL)
	{
		path = ".";
	}
	if(chdir(path) == ERROR)
	{
		fprintf(stderr, "%s: bad directory.\n", path);
	}
}