///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program which accept directory name from user and delete all empty files from that  //
//          directory.                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc, char* argv[])
{
	int ct=0;
	if(argc!=2)
	{
		printf("\nInavlid number of arguments!");
		return -1;
	}
	struct dirent *entry;
	struct stat fileStat;
	char name[500]={'\0'};
	DIR *dir;

	//opendir() system call to open the directory
	dir=opendir(argv[1]);

	if(dir==NULL)
	{
		printf("\nError: Unable to open directory\n");
		return -1;
	}

	//readdir() system call returns NULL when it reaches end
	while((entry=readdir(dir))!=NULL)
	{
		//absolute path
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&fileStat);

		if(S_ISREG(fileStat.st_mode))
		{
			//if it is regular file
				if((int)fileStat.st_size==0)
					{
						ct++;
						remove(name);			//delete specific file
						printf("\nDeleted %d empty files\n",ct);
					}
		}
		memset(&fileStat,0,sizeof(fileStat));
	}
	closedir(dir);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make dir="name" run
//////////////////////////////// ///////////////////////////////////////////////////////////////
