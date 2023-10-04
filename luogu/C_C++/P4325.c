#include<stdio.h>
#include<stdlib.h>


int main(void) {
	
	int num[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", num + i);
		num[i] = num[i] % 42;
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int flag = 1;
		for (int j = 0; j < i; j++)
		{
			if (num[i] == num[j])
				flag = 0;
		}

		if (flag == 1)
			sum++;
	}

	printf("%d", sum);

	system("pause");
	return 0;
}