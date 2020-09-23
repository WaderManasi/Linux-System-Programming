///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept directory name from user and print all file names from that    //
//       directory.                                                                          //
//       Demonstrates directory file handling
///////////////////////////////////////////////////////////////////////////////////////////////
#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
int main(int argc,char* argv[])
{
    DIR *dir;
    struct dirent *entry;

    if(argc!=2)
    {
        printf("\nInvalid no. of arguments\n");
        return -1;
    }
    //opndir() system call opens directory, returns pointer to structure-DIR
    //takes only one parameter i.e directory name
    
    if((dir=opendir(argv[1])) == NULL)
    {
        printf("\nError: Unable to open given directory!\n");
        return -1;
    }

    printf("\nContents of directory are: \n");
    //After opening directory we can read its entries 
    //Each entry contains two value: file_name : (its)inode_number
    //These entries are stored in different dirent structure
    /*	
		struct dirent 
		{
			ino_t d_ino; // i-node number
			char d_name[NAME_MAX + 1]; // filename 
		}
	*/

    //readdir() system call returns NULL when it reaches end of directory
    while((entry = readdir(dir))!=NULL)
    {
        printf("Name: %s\t Inode: %ld\n",entry->d_name,entry->d_ino);
    }
    
    //closedir() system call is used to close directory which is opened by opendir()
    closedir(dir);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make run
///////////////////////////////////////////////////////////////////////////////////////////////