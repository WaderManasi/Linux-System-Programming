////////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                      //
//                                                                                            //
//Name: Manasi Wader                                                                          //
//Date: 14th Sept-2020                                                                        //
//Topic: Program which accept file name from user through command line and read that          //
//          whole file.                                                                       //
////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int fd=0,ret=0;
    char data[30];
    if(argc!=2)
    {
        printf("\nError: Invalid number of arguments!\n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);
    //open() system call

    ret=read(fd,data,10);
    //read() system call

    if(ret==-1)
        {
            printf("\nUnable to read\n");
            close(fd);
            return -1;
        }
    printf("\nData from the file is: %s\n",data);
    close(fd);

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make file="data.txt" run
//remove exe: make clean
///////////////////////////////////////////////////////////////////////////////////////////////