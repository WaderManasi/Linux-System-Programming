///////////////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               
//                                                                                     
//Name:    Manasi Wader
//Program: Program to create file and give read ,write and execute.
//Language: C
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include<fcntl.h>               //for file handling (open)
#include<unistd.h>              //closing file
#include<stdio.h>
int main(
          int argc               //total cmd arguments
         ,char* argv[]           //array of cmd arguments
        )
{
    //create() system call to create regular file if it doesn't exists
    //open() and creat() return -1 on failure
    //the owner of the file is set to effective user ID of the process

    int fd;
    fd=creat("newfile.txt",0x777);  //0x: hex 777: all permissions rwx rwx rwx
    if(fd==-1)
        printf("\nUnable to create file\n");
    else
        printf("\nFile created with file descriptor: %d",fd);
    close(fd);
    return 0;
}
//////////////////////////////////////////////////////////////////////////