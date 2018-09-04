#define RL_BUFSIZE 2048
#include "unistd.h"
#include "stdio.h"
#include "main.h"
#include<stdlib.h>
char *lsh_read_line()
{
	int bufsize = RL_BUFSIZE;
	int pos = 0;
	char *buff = malloc(bufsize * sizeof(char));
	int c;

	if(!buff) {
		fprintf(stderr,"allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(1) {

		c = getchar();

		if(c == EOF){
			exit(EXIT_SUCCESS);
		} else if (c == '\n') {
			buff[pos] = '\0';
			return buff;
		} else {
			buff[pos] = c;
		}
		pos+=1;

		if(pos>=bufsize) {
			bufsize+= RL_BUFSIZE;
			buff = realloc(buff,bufsize);
			if(!buff) {
				fprintf(stderr,"allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}