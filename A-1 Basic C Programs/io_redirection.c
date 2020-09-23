// For demonstration of this program perform following activity
// Create file as input.txt in working directoy and write twonumbers in file as 10 20
// Create empty file as output.txt in working directory
// compile the program
// Run the program as
// ./a.out <input.txt >output.txt
// After this output.txt file contains output as 
// "Addition of 10 and 20 is 30"

#include<stdio.h>

int main()
{
	int no1,no2,no3,no4;

	printf("Demo of Input Ouptput redirection\n");

	scanf("%d %d %d %d",&no1,&no2,&no3,&no4);

	printf("Addition of %d %d %d %d is %d",no1,no2,no3,no4,no1+no2+no3+no4);
     
	return 0;
}
