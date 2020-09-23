///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept directory name from user and print all file names and its      //
//          types from that directory.                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        printf("\nInvalid number of arguments!\n");
        return -1;
    }
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    char filename[500]={'\0'};
    
    if((dir=opendir(argv[1]))==NULL)
    {
        printf("\nError: Unable to open directory!");
        return -1;
    }
    printf("\nContents of directory are: \n");
    /*
    struct dirent{
        ino_t d_ino;
        char d_name[NAME_MAX+1];
    }
    */
    while((entry=readdir(dir))!=NULL)
    {
        //creating absolute path: 
        //directory_name/file_name
        sprintf(filename,"%s/%s",argv[1],entry->d_name);
        stat(filename,&fileStat);

        printf("%30s : %ld : ",entry->d_name,entry->d_ino);
        if(S_ISREG(fileStat.st_mode))
         printf("Regular file\n");
        else if(S_ISDIR(fileStat.st_mode))
            printf("Directory file\n");
        else if(S_ISLNK(fileStat.st_mode))
            printf("Link\n");
    }

    closedir(dir);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make run
///////////////////////////////////////////////////////////////////////////////////////////////