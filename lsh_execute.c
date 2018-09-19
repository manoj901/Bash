#include "main.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "sys/types.h"
#include<string.h>

int lsh_execute(char **args)
{
	
	if(ashExecute(args)==0)
	return 1;
	//fprintf(stderr,"A");

	return lsh_launch(args);
}