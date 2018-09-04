#include "main.h"
#include "stdio.h"
#include<stdlib.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "malloc.h"
#include "string.h"
#include "dirent.h"
#include "time.h"
#include "pwd.h"
#include "grp.h"
#include<dirent.h>
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
int lsh_ls(char **args) {
	int checka = 0 , checkl = 0;
	for(int i = 1;args[i]!=NULL;i++) {
		if(strcmp(args[i],"-a")==0)
			checka = 1;
		else if(strcmp(args[i],"-l")==0)
			checkl = 1;
		else if(strcmp(args[i],"-al")==0 || strcmp(args[i],"-la")==0) {
			checka = 1;
			checkl = 1;
		}
		}

	struct dirent **list;
	int n = scandir(".",&list,NULL,alphasort);
	if(n<0) {
		perror("scandir");
		exit(EXIT_FAILURE);
	}

	if(checka == 1 && checkl == 0) {
	while(n>0) {
		n--;
		if(list[n]->d_type == 8)
		printf("%s\n",list[n]->d_name);
		else printf(ANSI_COLOR_RED"%s\n"ANSI_COLOR_RESET,list[n]->d_name);
		free(list[n]);
	}
	free(list);
	return 1;
	}

	if(checka == 0 && checkl == 0) {
	while(n>0) {
		n--;
		int k = 0;
		if(strcmp(list[n]->d_name,".")==0)
		k = 1;
		if(strcmp(list[n]->d_name,"..")==0)
		k=1;
		if(k==0) {
		if(list[n]->d_type == 8)
		printf("%s\n",list[n]->d_name);
		else printf(ANSI_COLOR_RED"%s\n"ANSI_COLOR_RESET,list[n]->d_name);
		free(list[n]);
	 }
	}
	free(list);
	return 1;
	}


	if(checka == 1 && checkl == 1) {
		char date[150];

	while(n>0) {
		n--;

		struct stat st; 
		if (stat(list[n]->d_name, &st) == -1) perror("stat error");
		strftime(date, 150, "%h %d %H:%M", localtime(&(st.st_ctime)));
		struct passwd *pw = getpwuid(st.st_uid);
    	struct group  *gr = getgrgid(st.st_gid);
		if(list[n]->d_type == 8) {
		printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x\t" : "-\t");
		printf("%lu\t%s\t%s\t%s\t%lu\t%s\n",st.st_nlink,pw->pw_name,gr->gr_name,date,st.st_size,list[n]->d_name);}
		else{
			printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x\t" : "-\t"); 
			printf("%lu\t%s\t%s\t%s\t%lu\t",st.st_nlink,pw->pw_name,gr->gr_name,date,st.st_size);
			printf(ANSI_COLOR_RED"%s\n"ANSI_COLOR_RESET,list[n]->d_name);}
		free(list[n]);
	}
	free(list);
	return 1;
	}

	if(checka == 0 && checkl == 1) {
		char date[150];

	while(n>0) {
		n--;

		struct stat st; 
		if (stat(list[n]->d_name, &st) == -1) perror("stat error");
		int k = 0;
		if(strcmp(list[n]->d_name,".")==0)
		k = 1;
		if(strcmp(list[n]->d_name,"..")==0)
		k=1;
		if(k==0) {
		strftime(date, 150, "%h %d %H:%M", localtime(&(st.st_ctime)));
		struct passwd *pw = getpwuid(st.st_uid);
    	struct group  *gr = getgrgid(st.st_gid);
		if(list[n]->d_type == 8) {
		printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x\t" : "-\t");
		printf("%lu\t%s\t%s\t%s\t%lu\t%s\n",st.st_nlink,pw->pw_name,gr->gr_name,date,st.st_size,list[n]->d_name);}
		else{
			printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x\t" : "-\t"); 
			printf("%lu\t%s\t%s\t%s\t%lu\t",st.st_nlink,pw->pw_name,gr->gr_name,date,st.st_size);
			printf(ANSI_COLOR_RED"%s\n"ANSI_COLOR_RESET,list[n]->d_name);}
		free(list[n]);
	}
	}
	free(list);
	return 1;
	}
	return 1;		
}
