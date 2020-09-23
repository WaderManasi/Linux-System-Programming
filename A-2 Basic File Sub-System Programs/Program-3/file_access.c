///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept file name and on mode and that program check whether our       //
//          process can access that file in accepted mode or not.                            //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
    int mode=0;
    /*access() sys call check whether calling process can access file pathname.
    If pathname is symbolic link,it is dereferenced!
    on SUCCESS (i.e all requested permissions granted) zero is returned
    on ERROR (i.e even if one bit requested has permission denied) -1 is returned
    */

    if(argc!=3)
    {
        printf("\nInvalid no. of arguments!\n");
        return -1;
    }

    if(strcmp(argv[2],"read")==0)       //read permission - r   (4)
        mode=R_OK;
    else if(strcmp(argv[2],"write")==0) //write permission - w  (2)
        mode=W_OK;
    else if(strcmp(argv[2],"execute")==0)   //execute permission -x  (1)
        mode=X_OK;

    if(access(argv[1],mode)<0)
        printf("\nError: Proccess cannot access this file for %s purpose\n",argv[2]);
    else   
        printf("\nProcess has %s access\n",argv[2]);
    
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make file="filename" mode="permission" run
///////////////////////////////////////////////////////////////////////////////////////////////