///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept directory name and file name from user and create file in      //
//          that directory.                                                                  //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        printf("\nInvalid no. of arguments!\n");
        return -1;
    }
    int fd=0,ret=0;
    
    //chdir() change directory system call
    ret=chdir(argv[1]);
    if(ret==-1)
        printf("\nError: Directory not changed!\n");
    else
        printf("\nDirectory changed successfully\n");
    fd=open(argv[2],O_CREAT);
    if(fd==-1)
        printf("\nError: File not created!\n");
    else
        printf("\nFile created successfully\n");

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make dir="name" file="name" run
///////////////////////////////////////////////////////////////////////////////////////////////