// CountCharLength.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	long c;
	long charLength = 0;
	long countLines = 0;
	long countHT = 0;
	long countSpaceLength = 0;
	//统计各字符出现的次数以及总共输入的字符数
	printf("统计字符出现的次数：\n");
	while ((c=getchar())!=EOF)
	{
		if (c=='\n'){
			countLines++;
		}
		else if (c==9)
		{
			countHT++;
		}
		else if (c==32){
			countSpaceLength++;
		}
		++charLength;
	}
	printf("Your input num of chars is : %ld \n",charLength);
	printf("Your input lines of chars is : %ld \n", countLines);
	printf("Your horizontal tab num of chars is : %ld \n", countHT);
	printf("Your space num of chars is : %ld \n", countSpaceLength);


	//将输入复制到输出，并将其中连续的多个空格用一个空格代替
	long ch;
	int i = 0;
	int lastSpacePosition = -2;

	printf("将输入复制到输出，并将其中连续的多个空格用一个空格代替：\n");
	
	for (i = 0; (ch = getchar()) != EOF;i++)
	{
		if (ch==32)
		{
			if (i - 1 != lastSpacePosition){
				putchar(ch);
			}
			
			lastSpacePosition = i;
			continue;
		}
		putchar(ch);
	}

	//将输入复制到输出，并将其中的制表符替换为\t，把回退符替换为\b，把反斜框替换为'\\'
	printf("将输入复制到输出，并将其中的制表符替换为\\t，把回退符替换为\\b，把反斜框替换为\\\\ : \n");

	long cha;
	while ((cha = getchar()) != EOF)
	{
		if (cha == 9)
		{
			printf("\\t");
			continue;
		}
		else if (cha==8){
			printf("\\b");
			continue;
		}
		else if (cha==92)
		{
			printf("\\\\");
			continue;
		}
		putchar(cha);
	}

	getchar();
	return 0;
}

