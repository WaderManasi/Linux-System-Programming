///////////////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               
//                                                                                     
//Name:    Manasi Wader
//Program: Program which accept filename and string from user and write that string into file.
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
    int fd=0,rd=0,wr=0;
    int offset;
    char str[]="Learn new technologies!\n";
    char buff[sizeof(str)];
    
    fd=open("demofile.txt",O_RDWR);
    if(fd==-1) 
    {
        printf("\nError: Unable to open file!\n ");
        return -1;
    }

    //write() system call to write data into file 
    //first parameter: file descriptor
    //second parameter: empty buffer
    //third parameter: no. of bytes to be written

    wr=write(fd,str,sizeof(str));

    if(wr!=sizeof(str))
        printf("\nError: Unable to write contents into file!\n");
    
    lseek(fd,0,SEEK_SET);

    rd=read(fd,buff,sizeof(buff));

    printf("\nContents written are: %s\n",buff);
    printf("\n");

    close(fd);
    close(rd);
    return 0;
}
//////////////////////////////////////////////////////////////////////////