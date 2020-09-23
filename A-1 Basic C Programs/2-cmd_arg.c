/////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS               //
//                                                                                     //
//Name:    Manasi Wader
//Program: Program which accept name from command line argument and 
//          display it on screen.
//Language: C
////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
int main(
         int argc               //total cmd arguments
        ,char* argv[]           //array of cmd arguments
        )
{
    printf("Name accepted through command line interface: %s",argv[1]);
    return 0;
}

//////////////////////////////////////////////////////////////////////////