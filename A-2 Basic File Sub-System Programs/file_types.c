///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program to find given file type                                                     //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
    struct stat fileStat;
    char name[255];

    printf("\nEnter file name to check its type: ");
    scanf("%s",name);

    //stat() return (>0) if file statistics are accessed
    if(stat(name,&fileStat)<0)
    {
        printf("\nError: Could'nt retrive file statistics\n");
        return -1;
    }

    //There are certain macros defined which checks file type
    //if file type matches then return true

    if(S_ISREG(fileStat.st_mode))  
        printf("\nRegular file\n");
    else if(S_ISDIR(fileStat.st_mode))  
        printf("\nDirectory\n");
    else if(S_ISCHR(fileStat.st_mode))  
        printf("\nCharacter special file\n");
    else if(S_ISBLK(fileStat.st_mode))  
        printf("\nBlock special file\n");
    else if(S_ISFIFO(fileStat.st_mode))  
        printf("\nFIFO (Pipe)\n");
    else if(S_ISLNK(fileStat.st_mode))  
        printf("\nSymbolic Link\n");
    else if(S_ISSOCK(fileStat.st_mode))  
        printf("\nSocket \n");
    else
        printf("\nFile type is unknown\n");
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////