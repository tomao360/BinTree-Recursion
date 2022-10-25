#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

int Add(int num)
{
	if (num == 101)
	{
		return 0;
	}

	printf("Num %d\n", num);
	return Add(num + 1) + 1;
}


int main_2()
{
	int a = Add(1);

	return 0;
}