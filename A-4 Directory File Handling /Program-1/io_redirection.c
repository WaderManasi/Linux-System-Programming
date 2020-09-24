///////////////////////////////////////////////////////////////////////////////////////////////
//                          LINUX SYSTEM PROGRAMMING WITH UNIX INTERNALS                     //
//                                                                                           //
//Name: Manasi Wader                                                                         //
//Topic: Program used to demonstrate concept of I/O redirection.                             //
///////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int no1,no2,no3;
    printf("\nDemo of io redirection!\n");
    scanf("%d %d %d",&no1,&no2,&no3);
    printf("\nAddition of %d %d %d is %d\n",no1,no2,no3,no1+no2+no3);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//compile: make build
//run: make args="<input>output" run
///////////////////////////////////////////////////////////////////////////////////////////////