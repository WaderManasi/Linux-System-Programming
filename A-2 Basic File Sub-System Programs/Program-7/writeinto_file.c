///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept file name from user through command line and write string in   //
//          that file.                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int fd=0;
    char arr[]="Writing some data into file.";
    int n=sizeof(arr)/sizeof(arr[0]);
    //total number of bytes

    int iret=0;

    if(argc!=2)
    {
        printf("\nError: Invalid number of arguments!\n");
        return -1;
    } 
    //open() system call to open in write mode
    fd = open(argv[1],O_WRONLY);

    if(fd == -1)
        printf("\nError: Unable to open file!\n");
    else
        printf("\nFile opened successfully! with file descriptor: %d\n",fd);
    
    iret=write(fd,          //file descriptor
               arr,         //character array
               n            //number of bytes to write
               );

    if(iret!=-1)
        {
            printf("\nData written into file successfully!\n");
            printf("\nData is: \n%s\n",arr);
        }
    else
        printf("\nError: Unable to write data into file\n");
    close(fd);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make rfile="data.txt" run
///////////////////////////////////////////////////////////////////////////////////////////////