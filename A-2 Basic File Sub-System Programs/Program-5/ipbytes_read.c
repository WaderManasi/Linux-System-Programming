////////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                      //
//                                                                                            //
//Name: Manasi Wader                                                                          //
//Date: 14th Sept-2020                                                                        //
//Topic: Program which accept file name and number of bytes from user and read that           //
//          number of bytes from file.                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int fd=0,ret=0,byte;

    char data[30];
    //character array to store data

    if(argc!=3)
    {
        printf("\nInvalid number of arguments!");
        return -1;
    }
    fd=open(argv[1],O_RDONLY);

    byte=atoi(argv[2]);
    //string to integer conversion
    //no. of bytes to read from the file
    
    ret=read(fd,data,byte);
    //read() system call
    
    if(ret==-1)
    printf("Error: Unable to read!");
    else
    printf("\nData from the file is: %s\n\n",data);
    close(fd);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make file="data.txt" bytes="10" run
//remove exe: make clean
///////////////////////////////////////////////////////////////////////////////////////////////