///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept directory name and file name from user and check whether       //
//          that file is present in that directory or not.                                   //           
///////////////////////////////////////////////////////////////////////////////////////////////
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
    int flag=0;
    if(argc!=3)
    {
        printf("\nInvalid no. of arguments\n");
        return -1;
    }
    DIR* dir;
    struct dirent *entry;       //structure containing inode and file name
    struct stat fileStat;       //structure which stores all info about file

    char filename[500]={'\0'};

    //open specified directory using system call opendir()
    dir=opendir(argv[1]);
    
    if(dir==NULL)
    {
        printf("\nError: Unable to open directory\n");
        return -1;
    }

    //readdir() system call returns NULL when it reaches end of file
    while((entry=readdir(dir))!=NULL)
    {
        //create absolute path
        sprintf(filename,"%s/%s",argv[1],entry->d_name);

        if(istrcmp(argv[2],entry->d_name)==0)
        flag=1;
    }
    if(flag==1)
        printf("\nFile present!\n");
    else
        printf("\nError: File not present!\n");

    closedir(dir);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make dir="name" file="name" run
///////////////////////////////////////////////////////////////////////////////////////////////