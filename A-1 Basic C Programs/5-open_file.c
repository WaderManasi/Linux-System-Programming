/////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               //
//                                                                                     //
//Name:    Manasi Wader
//Program: Program which accept file name from user and open that file.
//Language: C
/////////////////////////////////////////////////////////////////////////////////////////

#include<fcntl.h>               //for file handling (open)
#include<unistd.h>              //closing file
#include<stdio.h>
int main()
{
    int fd=0;
    fd=open(
            "demofile.txt",         //filename
            O_CREAT            //mode of opening file
        );
    if(fd==-1)
        printf("\nUnable to open file!\n");
    else
        printf("\nFile openend successfully!\n");
    close(fd);
    return 0;
}

//////////////////////////////////////////////////////////////////////////
