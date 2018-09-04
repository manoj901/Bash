#include "main.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int lsh_cd(char **args);
int lsh_pwd();
int lsh_echo(char **args);

int ashExecute(char **args) {

  if (args[0] == NULL) {
    return 1;
  } else if (strcmp(args[0], "cd")==0) {
    lsh_cd(args);
    return 0;
  } else if (strcmp(args[0],"pwd")==0) {
  	lsh_pwd();
  	return 0;
  } else if (strcmp(args[0],"echo")==0) {
  	lsh_echo(args);
  	return 0;
  } else if (strcmp(args[0],"ls")==0) {
  	lsh_ls(args);
  	return 0;
  } else if (strcmp(args[0],"pinfo")==0) {
  	lsh_pinfo(args);
  	return 0;
  } 
  return 1;
} 

int lsh_cd(char **args)
{
	if(args[1] == NULL) {
		fprintf(stderr,"expected argument is \"cd <directory_name>\"\n");
	} else {
		if (chdir(args[1])!=0) {
			perror("bash");
		}
	}
	return 1;
};

int lsh_pwd()
{
	getcwd(cwd,200);
	printf("%s\n",cwd);
	return 1;
};

int lsh_echo(char **args) {
	int i;
	if(args[1][0] == 34) {
		for(i=1;;i++) {
			if(args[i][strlen(args[i])-1] == 34 && i!=1) {
				if(args[i][0] == 34) {
					for(int j=1;j<strlen(args[i])-1;j++)
					printf("%c",args[i][j]);
				} else {
					for(int j=0;j<strlen(args[i])-1;j++)
					printf("%c",args[i][j]);
					printf(" ");
				}
				break;
			}
			if(i==1) {
			for(int j=1;j<strlen(args[1]);j++)
			printf("%c",args[1][j]);
			printf(" ");}
			else
			printf("%s ",args[i]);
			
		} 
	} else {
			for(i=1;args[i]!=NULL;i++)
			printf("%s ",args[i]);
		}
	printf("\n");
	return 1; 
};