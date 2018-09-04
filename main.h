void lsh_loop();
#include<stdlib.h>
char *lsh_read_line();
char **lsh_split_line(char *line);
int lsh_num_builtins();
int lsh_cd(char **args);
int lsh_launch(char **args);
int lsh_execute(char **args);
int ashExecute(char **args);
void cwdStr(char *cwd);
int lsh_cd(char **args);
int lsh_echo(char **args);
int lsh_ls(char **args);
void lsh_pinfo(char **args);
int bgcount;
int PID , VAL;
typedef struct process {
	int id;
	char name[10000];
	struct process* next;
} process;

process* head;
#include <sys/wait.h>
#include <sys/types.h>
char HOME[200],/*user[300],*/hostname[300],cwd[200];