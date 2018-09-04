#define BUFSIZE 128
#define DELIM " \t\r\n\a"
#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char **lsh_split_line(char *line)
{
	int bufsize = BUFSIZE;
	int pos = 0;
	char **tokens = malloc(BUFSIZE * sizeof(char*));
	char *token;

	if(!tokens) {
		fprintf(stderr, "token allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line,DELIM);
	while(token!=NULL) {
		tokens[pos] = token;
		pos=pos+1;

		if(pos >= bufsize) {
			bufsize+= BUFSIZE;
		tokens = realloc(tokens,bufsize*sizeof(char*));
		if(!tokens) {
			fprintf(stderr,"allocation error\n");
			exit(EXIT_FAILURE);
		}
		}

		token = strtok(NULL,DELIM);
	}
	tokens[pos] = NULL;
	return tokens;

}