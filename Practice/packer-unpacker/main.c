/* 
Apllication which is used to combine all regular files from directory into one regular file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

//myexe dir_name file_name
//myexe argv[1]  argv[2]
//argv[1]:              directory_name containing many files
//argv[2]:              file name 
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("\nInvalid number arguments!\n");
        return -1;
    }
    DIR *dir=NULL;
    struct dirent entry;
    
    dir=opendir(argv[1]);
    if(dir==NULL)
    {
        printf("\nError: Unable to open %s .",argv[1]);
        return -1;
    }

    return 0;
}