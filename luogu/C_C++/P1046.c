#include<stdio.h>
#include<stdlib.h>


int main(void) {
	
	int arr[10];
	int length;
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", arr + i);
	}

	scanf("%d", &length);

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] <= 30 + length)
		{
			sum++;
		}
	}
	printf("%d", sum);

	system("pause");
	return 0;
}