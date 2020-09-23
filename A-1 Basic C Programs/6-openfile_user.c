/////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               //
//                                                                                     //
//Name:    Manasi Wader
//Program: To demonstrate open() system call.Program which accept file name from user 
//          and open that file 
//          and if file is not opened properly then display error message properly.
//Language: C
/////////////////////////////////////////////////////////////////////////////////////////

#include<fcntl.h>               //for file handling (open)
#include<unistd.h>              //closing file
#include<stdio.h>
int main(
          int argc               //total cmd arguments
         ,char* argv[]           //array of cmd arguments
        )
{
    int fd=0;
    
    //opening file in read mode
    fd=open(
            argv[1],            //filename input from user through command line 
            O_RDONLY            //mode of opening file
        );
    if(fd==-1)
        printf("\nUnable to open file!\n");
    else
        printf("\nFile openend successfully! with file descriptor %d in read mode\n",fd);
    
    //opening file in write mode
    fd=open(
            argv[1],            //filename input from user through command line 
            O_WRONLY            //mode of opening file
        );
    if(fd==-1)
        printf("\nUnable to open file!\n");
    else
        printf("\nFile openend successfully! with file descriptor %d in wriite mode\n",fd);
    
    //opening file in write and read mode
    fd=open(
            argv[1],            //filename input from user through command line 
            O_RDWR              //mode of opening file
        );
    if(fd==-1)
        printf("\nUnable to open file!\n");
    else
        printf("\nFile openend successfully! with file descriptor %d in read mode\n",fd);
   
    close(fd);
    return 0;
}

// O_APPEND Append to the end of file on each write.
// O_CREAT Create the file if it doesn't exist.
// O_EXCL Generate an error if O_CREAT is also specified and the file already exists. 
// O_TRUNC If the file exists and if it is successfully opened for either write-only or read�write, truncate its length to 0.
// O_DSYNC Affects a file's attributes only when they need to be updated to reflect a change in the file's data.
// O_SYNC data and attributes are always updated synchronously

// This flags can be or.
//////////////////////////////////////////////////////////////////////////