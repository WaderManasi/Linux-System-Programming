/* 
Apllication which is used to combine all regular files from directory into one regular file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

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
    int fddest=0;
    DIR *dir=NULL;
    struct dirent *entry;
    struct stat sobj;       //object of stat() structure
    char name[257]={'\0'};

    dir=opendir(argv[1]);
    if(dir==NULL)
    {
        printf("\nError: Unable to open %s .",argv[1]);
        return -1;
    }

    fddest=creat(argv[2],0777); //create new file to merge data
    if(fddest==-1)
    {
        printf("\nError: Unable to create new file\n");
        return -1;
    }

    printf("\nName of files are: \n\n");
    while((entry=readdir(dir))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("%s\n",entry->d_name);  //with this we get wrong values ,hence we create absolute path //printf("%d",)
            printf("%ld bytes \n\n",sobj.st_size);
        }
    }

    closedir(dir);
    return 0;
}