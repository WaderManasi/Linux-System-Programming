#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
    struct stat s;
    int ret=0,fd=0;
    stat(argv[1],&s);
    printf("\nis on physical device: %d\n",(int)s.st_dev);
    return 0;
}
/*
st_dev: returns positive value if it resides on physical device
        else return 0 if it resides on virtual device (NFS mount)
        and -1 on error
*/