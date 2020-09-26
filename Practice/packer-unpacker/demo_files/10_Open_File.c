// This program demonstate open system call

#include<stdio.h>
#include<fcntl.h>

int main()
{

int fd;

// Opening file in read mode
fd = open("/root/Desktop/new.txt",O_RDONLY);
if(fd == -1)
{
	printf("Unable to open the file\n");
}
else
{
	printf("File is successfully opened with file descriptor %d in read mode \n",fd);
}

// Opening file in write mode
fd = open("/root/Desktop/new.txt",O_WRONLY);
if(fd == -1)
{
	printf("Unable to open the file\n");
}
else
{
	printf("File is successfully opened with file descriptor %d in write mode \n",fd);
}

// Opening file in write mode
fd = open("/root/Desktop/new.txt",O_RDWR);
if(fd == -1)
{
	printf("Unable to open the file\n");
}
else
{
	printf("File is successfully opened with file descriptor %d in read & write mode \n",fd);
}

// Uses of other macro while opening a file

// O_APPEND Append to the end of file on eachrite.
// O_CREAT Create the file if it doesn't exist.
// O_EXCL Generate an error if O_CREAT is also specified and the file already exists. 
// O_TRUNC If the file exists and if it is successfully opened for either write-only or read–write, truncate its length to 0.
// O_DSYNC Affects a file's attributes only when they need to be updated to reflect a change in the file's data.
// O_SYNC data and attributes are always updated synchronously

// This flags can be or.

fd = open("/root/Desktop/new.txt",O_WRONLY | O_TRUNC);
return 0;
