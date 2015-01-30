// InputOutput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	//Print the value of EOF
	printf("The value of EOF is :%d \n", EOF);

	int c = getchar();

	while (c != EOF){
		putchar(c);
		printf("The value of getchart() is : %d \n", c);
		c = getchar();
		printf("The value of (getchart()!=EOF) is : %d \n",c != EOF);
	}
	
	

	return 0;
}

