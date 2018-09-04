#include "main.h"
#include "string.h"

void cwdStr(char cwd[]) {
	int i , p = 0;

	for(i=0;HOME[i]!='\0';i++) {
		if(cwd[i]!=HOME[i]) {
			p = 1;
			break;
		}
	}

	if(p==1){
		return;
	} else {
		int length = strlen(cwd);
		char newcwd[length-i+5];
		newcwd[0] = '~';
		for(int j=1;i<length;i++,j++)
		newcwd[j]=cwd[i];
		strcpy(cwd,newcwd);
	}
}