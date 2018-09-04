#include "main.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#define ANSI_COLOR_GREEN    "\e[1;32m"
#define ANSI_COLOR_WHITE    "\e[1;37m"
#define ANSI_COLOR_BLUE    "\e[1;34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED   "\e[1;32m"

void lsh_loop()
{
	char *line;
	char ** args;
	int stat;

	char* user = getenv("USER");
	gethostname(hostname,300);
	getcwd(cwd,200);
	strcpy(HOME,cwd);

	do{
		getcwd(cwd,200);
		if(strcmp(cwd,HOME)==0) {
			strcpy(cwd,"~");
		} else {
		cwdStr(cwd);
		}
		printf(ANSI_COLOR_RED"<"ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN"%s@%s"ANSI_COLOR_RESET,user,hostname);
		printf(ANSI_COLOR_WHITE":"ANSI_COLOR_RESET);
		printf(ANSI_COLOR_BLUE"%s"ANSI_COLOR_RESET,cwd);
		printf(ANSI_COLOR_RED"> "ANSI_COLOR_RESET);
		//take the input
		line = lsh_read_line();
		//split the line using linebreakers into commands to execute
		args = lsh_split_line(line);
		//execute them 
		stat = lsh_execute(args);

		//free the space
		free(line);
		free(args);
	} while(stat);
}