/* 
Apllication which is used to combine all regular files from directory into one regular file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

//myexe dir_name file_name
//myexe argv[1]  argv[2]
//argv[1]:              directory_name containing many files
//argv[2]:              file name 

struct FileInfo
{
    char fname[257];        //file name
    int fsize;              //file size
};

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("\nInvalid number arguments!\n");
        return -1;
    }
    int fddest=0,ret=0,fdsrc=0;
    DIR *dir=NULL;
    struct FileInfo fobj;   //object of FileInfo structure
    struct dirent *entry;
    struct stat sobj;       //object of stat structure
    char *buff;

    fdsrc=open(argv[1],O_RDONLY); //create new file to merge data
    if(fdsrc==-1)
    {
        printf("\nError: Unable to create new file\n");
        return -1;
    }

    printf("\nName of files are: \n\n");
    while((ret=read(fdsrc,&fobj,sizeof(fobj)))!=0)
    {
        printf("\nFile name %s :Size: %d \n",fobj.fname,fobj.fsize);
        fddest=creat(fobj.fname,0777);
        
        //lseek(fdsrc,fobj.fsize,SEEK_CUR);
         buff=(char*)malloc(fobj.fsize);
        read(fdsrc, buff, fobj.fsize);
        write(fddest,buff,fobj.fsize);

        free(buff);

        close(fddest);
    }
    close(fdsrc);
    return 0;
}