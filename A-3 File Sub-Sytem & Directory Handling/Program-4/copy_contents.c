///////////////////////////////////////////////////////////////////////////////////////////////
//                      LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                         //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Date: 18th Sept-2020                                                                       //
//Topic: Program which accept two file names from user and copy the contents of an           //
//          existing file into newly created file.                                           //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int fd1=0,fd2=0,fd3=0,rd=0,wr=0;
    char read_data[50],copy_data[50];
    if(argc!=3)
    {
        printf("\nInavlid number of arguments!\n");
        return -1;
    }
    fd1=open(argv[1],O_RDONLY);
    if(fd1==-1)
        printf("\nError: Unable to open %s\n",argv[1]);
    else
        printf("\n%s opened successfully with file descriptor %d\n",argv[1],fd1);
    
    rd=read(fd1,read_data,50);
    close(fd1);

    fd3=open(argv[2],O_RDWR);
    if(fd3==-1)
        printf("\nError: Unable to open %s in write mode\n",argv[2]);
    else
        printf("\n%s successfully opened to write\n",argv[2]);

    
    wr=write(fd3,read_data,50);

    if(wr==-1)
        printf("\nError: Unable to write data!\n");
    else
        printf("\nData written successfully!\nData is: %s\n",read_data);

    return 0;
}