#include "main.h"
#include "stdio.h"
#include "string.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/wait.h"
#include "sys/types.h"
#include "limits.h"
#include "stdlib.h"
#define ANSI_COLOR_YELLOW    "\e[1;33m"
#define ANSI_COLOR_RESET   "\x1b[0m"
void lsh_pinfo(char **args) {
	char pid[100];
	char exepath[1000];
	char symlink[1000];
	if(args[1]==NULL)
	sprintf(pid,"%d",getpid());
	else strcpy(pid,args[1]);

	char dir[] = "/proc/";
	strcat(dir,pid);
	strcpy(symlink,dir);
	strcat(symlink,"/exe");
	strcat(dir,"/stat");

	int siz = readlink(symlink,exepath,1000);
	if(siz==-1)
		strcpy(exepath,"link is broken");
	else {
		exepath[siz] = '\0';
		cwdStr(exepath);
	}

	int fd = open(dir,O_RDONLY);
	if(fd==-1){
		perror("ash");
		return;
	}
	char content[5000];
	read(fd,content,500);
	char** mata = lsh_split_line(content);
	 //printf("pid -- %s\nProcess Status -- %s\nVirtual Memory -- %s\nExecutable Path -- %s\n", mata[0], mata[2], mata[23], exepath);
	printf(ANSI_COLOR_YELLOW"pid -- "ANSI_COLOR_RESET);
	printf("%s\n",mata[0]);
	printf(ANSI_COLOR_YELLOW"Process Status -- "ANSI_COLOR_RESET);
	printf("%s\n",mata[2]);
	printf(ANSI_COLOR_YELLOW"Virtual Memory -- "ANSI_COLOR_RESET);
	printf("%s\n",mata[23]);
	printf(ANSI_COLOR_YELLOW"Executable Path -- "ANSI_COLOR_RESET);
	printf("%s\n",exepath);


}