///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program to display statistics of a (info) file using stat system function           //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
    int ret=0,fd=0;
    struct stat fileStat;

    //stat function accept fileame as parameter
    ret=stat("file.txt",&fileStat);
    if(ret==-1)
    {
        printf("\nStat function fail\n");
        return -1;
    }
    printf("\nCalling function stat\n\n");
    printf("File size: %d bytes\n",(int)fileStat.st_size);
    printf("No. of links: \n",(int)fileStat.st_nlink);
    printf("File inode: \n",(int)fileStat.st_ino);
    printf("File system number: \n",(int)fileStat.st_dev);
    printf("Number of blocks allocated for file: \n",(int)fileStat.st_blocks);
    printf("File permission: \t");

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make run
///////////////////////////////////////////////////////////////////////////////////////////////