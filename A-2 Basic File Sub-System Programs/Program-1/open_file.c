////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                  //
//                                                                                        //
//Name: Manasi Wader                                                                      //
//Date: 13th Sept-2020                                                                    //
//Topic: Program which accept file name from user and open that file.                     //
////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(
            int argc, char* argv[]
        )
{
    int fd=0;                       //file descriptor

    if(argc!=2)
    {
        printf("\nError: Invalid number of arguments!\n");
        return -1;
    }
    
    fd = open(argv[1],O_RDONLY);    //open() system call
    if(fd == -1)
        printf("\nError: Unable to open file!\n");
    else
        printf("\nFile opened successfully! with file descriptor: %d\n",fd);
    close(fd);
    return 0;
}   

////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make args="file_name" run
////////////////////////////////////////////////////////////////////////////////////////