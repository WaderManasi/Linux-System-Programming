///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept directory name from user and print name of such a file         //
//         having largest size.                                                              //
///////////////////////////////////////////////////////////////////////////////////////////////
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
    int max=0;
    if(argc!=2)
    {
        printf("\nInvalid no. of arguments\n");
        return -1;
    }
    DIR* dir;
    struct dirent *entry;       //structure containing inode and file name
    struct stat fileStat;       //structure which stores all info about file

    char filename[500]={'\0'};

    //open specified directory
    dir=opendir(argv[1]);

    if(dir==NULL)
    {
        printf("\nUnable to open directory\n");
        return -1;
    }    

    //Directory contents:
    while((entry=readdir(dir))!=NULL)
    {
        sprintf(filename,"%s/%s",argv[1],entry->d_name);
        stat(filename,&fileStat);

        //check if file is regular
        if(S_ISREG(fileStat.st_mode))
        {
            if(max<(int)fileStat.st_size)
            {
                memset(filename,0,sizeof(filename));
                strcpy(filename,entry->d_name);
                max=(int)fileStat.st_size;
            }
        }
        memset(&fileStat,0,sizeof(fileStat));
    }

    printf("File with maximum size : %s \tSize: %d\n",filename,max);
    closedir(dir);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make run
///////////////////////////////////////////////////////////////////////////////////////////////