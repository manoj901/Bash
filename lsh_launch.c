#include "main.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "sys/types.h"
#include<string.h>
int PID , VAL;
void handler(int sig)
{
  pid_t pid;
  pid = wait(NULL);
  if(pid!=-1) {
  	VAL = 1;
  	PID = pid;
  }
   printf("\nprocess with pid %d exited normally.\n", pid);
  return;
}

int lsh_launch(char **args)
{
	pid_t pid;
	int status;
	signal(SIGCHLD, handler);

	int lo = 0,flag = 0;
	while(args[lo]!=NULL)
	lo++;
	if(args[lo-1][strlen(args[lo-1])-1]=='&') {
	flag = 1;
	args[lo-1][strlen(args[lo-1])-1]='\0'; }
	

	pid = fork();
	if(pid==0) {
		if(ashExecute(args)==0); else
		if(execvp(args[0],args) == -1) {
			perror("bash");
		}
		if(VAL==1)
	 	printf("\n[%d] done.\n", PID);
		exit(EXIT_FAILURE);
	} else if (pid<0) {
		perror("bash");
	} else {
		if(!flag) {
		do{
			waitpid(pid,&status,WUNTRACED);
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
		} else {
			waitpid(pid,&status,WNOHANG);
		}
	}

	return 1;
}