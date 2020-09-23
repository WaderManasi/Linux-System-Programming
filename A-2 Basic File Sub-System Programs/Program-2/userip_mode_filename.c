///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Date: 13th Sept-2020                                                                       //
//Topic: Program which accept file name and mode from user (through command line) and then   //
//          open that file in specified mode.                                                // 
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(
            int argc,char *argv[]
        )
{
    int fd=0;
    if(argc!=3)
    {
        printf("\nInvalid number of arguments!");
        return -1;
    }
    if(strcmp(argv[2],"READ")==0)
    {
        fd=open(argv[1],O_RDONLY);
        printf("\nFile openend in READ ONLY mode succcessfully! with file descriptor %d\n",fd);
    }
    else if(strcmp(argv[2],"WRITE")==0)
    {
        fd=open(argv[1],O_WRONLY);
        printf("\nFile openend in WRITE ONLY mode succcessfully! with file descriptor %d\n",fd);
    }
    else if(strcmp(argv[2],"BOTH")==0)
    {
        fd=open(argv[1],O_RDWR);
        printf("\nFile openend in WRITE READ mode succcessfully! with file descriptor %d\n",fd);
    }
    close(fd);
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make file="file_name" mode="READ/WRITE/BOTH" run
///////////////////////////////////////////////////////////////////////////////////////////////