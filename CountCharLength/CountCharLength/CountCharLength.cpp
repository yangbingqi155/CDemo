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
	//ͳ�Ƹ��ַ����ֵĴ����Լ��ܹ�������ַ���
	printf("ͳ���ַ����ֵĴ�����\n");
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


	//�����븴�Ƶ�������������������Ķ���ո���һ���ո����
	long ch;
	int i = 0;
	int lastSpacePosition = -2;

	printf("�����븴�Ƶ�������������������Ķ���ո���һ���ո���棺\n");
	
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

	//�����븴�Ƶ�������������е��Ʊ���滻Ϊ\t���ѻ��˷��滻Ϊ\b���ѷ�б���滻Ϊ'\\'
	printf("�����븴�Ƶ�������������е��Ʊ���滻Ϊ\\t���ѻ��˷��滻Ϊ\\b���ѷ�б���滻Ϊ\\\\ : \n");

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

