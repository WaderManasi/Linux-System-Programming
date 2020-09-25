///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept directory name from user and create new directory of that      //
//          name.                                                                            //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int ret=0;
    ret=mkdir(argv[1],0x777);
    if(ret==-1)
    {
        printf("\nError: Unable to create directory");
        return -1;
    }
    printf("\nNew directory created!\n");
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make run
///////////////////////////////////////////////////////////////////////////////////////////////