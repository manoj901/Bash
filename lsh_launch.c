#include "main.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "sys/types.h"
#include<string.h>
int PID , VAL;
void child_checking( ){
	pid_t w_pid;
	int status;
	w_pid = waitpid(-1,&status,WNOHANG);

	if(w_pid > 0 && WIFEXITED(status)==1)
		printf("\nProcess brexited normally with pid:%d\n",w_pid);
	if(w_pid > 0 && WIFSIGNALED(status)==1)
		printf("\nProcess exited due to a signal generated with pid:%d\n",w_pid);
	//fprintf(stderr,"a");
}

int lsh_launch(char **args)
{
	pid_t pid;
	int status;

	int lo = 0,flag = 0;
	while(args[lo]!=NULL)
	lo++;
	if(lo==0)
	return 1;
	 if(strcmp(args[lo-1],"&")==0){
        flag = 1;
        args[lo-1]=NULL;
        lo--;
    }
	
	//fprintf(stderr,"b");
	pid = fork();
	
	if(pid==0) {
		if(ashExecute(args)==0); else
		if(execvp(args[0],args) == -1) {
			perror("bash");
		}
		if(!flag)
		    setpgid(0,0);
	//	fprintf(stderr,"c");
		exit(EXIT_FAILURE);
	} else if (pid<0) {
		perror("bash");
	} else {
		if(!flag) {
		do{
			waitpid(pid,&status,WUNTRACED);
	//		fprintf(stderr,"d");
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
		} else {
			signal(SIGCHLD,child_checking);
	//		fprintf(stderr,"f");
		}
	}

	//fprintf(stderr,"g");
	return 1;
}