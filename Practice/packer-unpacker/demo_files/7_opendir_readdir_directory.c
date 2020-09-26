// This program demonstates directory file handling

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main() 
{
	DIR *dir;
	struct dirent *entry;
	
	// opendir() system call opens directory and returns pointer to DIR structure
	// opendir() accept only one parameter that is name of the directory to be open

	if ((dir = opendir("NewDirectory")) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	printf("Contents of directory as \n");

	// After opening a directory we can read the directory contents means directory entries
	// Each directory entry contains two things as name of the file and its inode number
	// This contents are stored in dirent structure which is as follows
	/*	
		struct dirent 
		{
			ino_t d_ino; // i-node number
			char d_name[NAME_MAX + 1]; // filename 
		}
	*/
	 
	while ((entry = readdir(dir)) != NULL)
	{
	      printf("Name: %s\t Inode: %d\n", entry->d_name,entry->d_ino);
	}
	
	// readdir() system call returns NULL when it reach end of the directory.

	// closedir() close the directory which is opened by opendir()
	closedir(dir);
return 0;
}
