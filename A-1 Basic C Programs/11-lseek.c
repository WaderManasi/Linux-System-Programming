///////////////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               
//                                                                                     
//Name:    Manasi Wader
//Program: offset (lseek)
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
    int fd=0,offset=0;
    fd=open("demo_file.txt",O_RDWR);
    if(fd==-1)
        printf("\nError: Unable to open\n");
    
    //when file is opened in read | write mode then offset is always zero

    //to cchange current file offset we use lseek() function
    offset=lseek(fd,0,SEEK_SET);
    printf("offset is %d\n",offset);

    //SEEK_SET :starting of file i.e 0
    //SEEK_CUR :current offset of file
    //SEEK_END :last byte offset of file

    //now we change current offst by 5 bytes
    offset=lseek(fd,5,SEEK_CUR);
    printf("offset is %d\n",offset);

    //move the curernt byte offset backwards
    offset=lseek(fd,-22,SEEK_CUR);
    printf("offset is %d\n",offset);

    //once is goes beyond 0 index then value returned is -1

    offset = lseek(fd,0,SEEK_END);
	printf("Last byte offset is %d\n",offset);
    return 0;
}
//////////////////////////////////////////////////////////////////////////