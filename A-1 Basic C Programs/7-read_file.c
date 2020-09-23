///////////////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               
//                                                                                     
//Name:    Manasi Wader
//Program: To demonstrate read() system call, which accept file name and read first 5 characters from it.
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
    int fd;
    int ret;
    int offset;
    char buff[100];

    fd=open("demo_file.txt",O_RDONLY);
    if(fd==-1)
    {
        printf("\nUnable to open file!\n");
        return -1;
    }

    //With the read() system call we can read contents of file
    //first parameter: file descriptor
    //second parameter: empty buffer
    //third parameter: no. of bytes to read

    ret = read(fd,buff,5);

    //read() system call returns the number of bytes read from file strores in buff array
    // it return -1: if file was no able to read
    // it return 0: if it reaches eof while reading

    if(ret!=5)
    {
        printf("\nUnable to read contents\n");
    }
    printf("\nRead contents are: \n%s\n",buff);
    //after reading 5 bytes current offset is changed to 5
    
    printf("Initially offset was: %d",offset);
    printf("\n");
    offset = lseek(fd,0,SEEK_CUR);
    printf("After reading 5 bytes offset is: %d",offset);
    printf("\n");
    return 0;
}
//////////////////////////////////////////////////////////////////////////