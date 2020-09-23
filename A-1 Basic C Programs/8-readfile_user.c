///////////////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               
//                                                                                     
//Name:    Manasi Wader
//Program: To demonstrate read() system call, which accept file name and read entire file
//Language: C
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include<fcntl.h>               //for file handling (open)
#include<unistd.h>              //closing file
#include<stdio.h>
#define MAX 100
int main(
          int argc               //total cmd arguments
         ,char* argv[]           //array of cmd arguments
        )
{
    int ret;
    FILE *fp=NULL;                   //file pointer
    char ch;
    char buff[MAX];

    fp=open("demo_file.txt","r+");
    if(fp==NULL)
    {
        printf("\nUnable to open file!\n");
    }
    printf("File contents before fseek are\n");
	while((ch = fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}

	ret = fseek(fp,5,SEEK_SET);
    if(ret != 0)
	{
		printf("Unable to seek\n");
	}

	// Write character 'z' at the new position
	fputc('z',fp);

	printf("\n\nFile contents before fseek are\n");

	// Set the file position to the begining
	fseek(fp,0,SEEK_SET);

	// The above effect can be achived through the function rewind
	// rewind() function sets file position indecator to start of the file

	rewind(fp);

	while((ch = fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
    fclose(fp);
    return 0;
}
//////////////////////////////////////////////////////////////////////////