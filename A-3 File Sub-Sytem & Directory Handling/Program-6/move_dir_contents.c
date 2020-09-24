///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept two directory names from user and move all files from          //
//          source directory to destination directory.                                       //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
    DIR *dir;
    struct dirent *entry;       //to get d_name and d_ino

    if(argc!=3)
    {
        printf("\nInvalid no. arguments!");
        return -1;
    }
    
    char old_path[500]={'\0'};
    char new_path[500]={'\0'};

    //opening the specified directory using opendir() system call
    dir=opendir(argv[1]);           //first directory name

    //error in opening file
    if(dir==NULL)
    {
        printf("\nError: Unable to open directory!");
        return -1;
    }

    //traversing the entire directory using readdir() system call
    while((entry=readdir(dir))!=NULL)
    {
        //from source path
        sprintf(old_path,"%s/%s",argv[1],entry->d_name);
        //to destination path
        sprintf(new_path,"%s/%s",argv[2],entry->d_name);

        //move the file
        rename(old_path,new_path);
        memset(&old_path,0,sizeof(old_path));
        memset(&new_path,0,sizeof(new_path));
    }
    closedir(dir);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make dir1="name" dir2="name" run
///////////////////////////////////////////////////////////////////////////////////////////////