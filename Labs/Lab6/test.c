#include <stdio.h>

int main()
{
	int value = fork();
	printf("Value = %d\n", value);
	if(value == 0)
	{
		int a = fork();
		printf("A = %d\n", a);
	}
	return 0;
}
