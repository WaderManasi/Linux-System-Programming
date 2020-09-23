///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Date: 22 Sept-2020                                                                         //
//Topic: program which accept file name from user and print all information about that file. //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        printf("\nInvalid nummber of arguments!\n");
        return -1;
    }
    int ret=0;
    struct stat fileStat;
    /*
    stat is a defined structure
    this function is used to print all details ABOUT file
    accept single parameter - file name
    */
    ret=stat("data.txt",&fileStat);
    if(ret==-1)
    {
        printf("\nStat function failed!\n");
        return -1;
    }
    printf("\nStat function called!...Displaying file details:\n");
    printf("\nFile size: %d",(int)fileStat.st_size);
    printf("\nFile inode: %d",(int)fileStat.st_ino);
    printf("\nFileSystem number: %d",(int)fileStat.st_dev);
    printf("\nNo. of links: %d",(int)fileStat.st_nlink);
    printf("\nNo. of blocks allocated to the file: %d",(int)fileStat.st_blocks);
    
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make run
///////////////////////////////////////////////////////////////////////////////////////////////