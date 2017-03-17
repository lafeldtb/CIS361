#define MAXLINE 80
#define MAXARG 20

#include <stdio.h>
#include <string.h>

void background(char * cmd);

int main()
{
	char cmd[MAXLINE];

	for (;;)
	{
		printf("mysh$ ");
		fgets(cmd, MAXLINE, stdin);	//read a command from the user

		// if the command in cmd is "exit\n", then terminate this program;
		// otherwise, create a child process to handle that command.
		if(!strcmp(cmd, "exit\n"))
			exit(1);	

		int childpid;

		if((childpid = fork()) == 0)
		{
			background(cmd);
		}
		wait(&childpid);
	}
}

void background(char * cmd)
{
	int i = 0;
	char *argv[MAXARG];

	char *tok = strtok(cmd, "\t \n");
	while(i < MAXARG && tok != NULL)
	{
		argv[i] = tok;

		tok = strtok(NULL, "\t \n");
		i++;
	}

	execvp(argv[0], argv);

	// Here you may use strtok(cmd, "\t \n") to get each token 
	// from cmd and then store it in array argv sequentially.
	// strtok() returns NULL when the end of cmd is reached
	exit(0);
}

