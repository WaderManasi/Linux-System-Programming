/*
Implement custom "cp" command which is used to copy contents from one file to other.

Usage:
    file1.txt file2.txt
    copy file1 data contents into file2
*/
#include<stdio.h>
#include<unistd.h>      //most of macros
#include<stdlib.h>      //lib fun prototype
#include<fcntl.h>

//cp file1.txt  file2.txt
//cp argv[1]    argv[2]
//argv[1]       Open file in read mode
//argv[2]       Create a new line 

void CP_Command(char *src,char *dest)
{
    int ret=0,wr=0,fdsrc=0,fddest=0;
    char buff[1024]={'\0'};         //1024 : 1kb
    fdsrc=open(src,O_RDONLY);
    if(fdsrc==-1)
        printf("\nError: Source file %s not created!\n",src);
    
    fddest=creat(dest,0777);
    if(fddest==-1)
    {
        printf("\nError: Unable to create destination file %s!\n",dest);
    }
    
    //do not use exit() syscall in between the program, generally use it at end of main function    
    while((ret=read(fdsrc,buff,sizeof(buff)))!=0)
    {
        if(ret==-1)
        {
            printf("\nError: Unable to read entire data");
            close(fdsrc);
            close(fddest);
            return ;
        }
        wr=write(fddest,buff,ret);
        if(wr==-1)
            {
                printf("\nError: Unable to write data into file\n");
                close(fdsrc);
                close(fddest);
                return;
            }
        else
            printf("\nData written succesfully!\n");
    }

    close(fddest);
    close(fdsrc);

    printf("\nCopy successful!\n");
}

int main(int argc,char* argv[])
{
    
    if(argc!=3)
    {
        printf("\nError: Invalid number of arguments!\n");
        printf("\nUsage: cp src.txt dest.txt\n");
        return -1;
    }

    CP_Command(argv[1],argv[2]);
    
    return 0;       //in main: exit(0)
}