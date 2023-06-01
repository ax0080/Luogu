#include<stdio.h>
#include<stdlib.h>


int main(void) {
	
	int n;
	scanf("%d", &n);

	int arr[10000];
	int max = 1;
	int conti = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		if (i > 0)
		{
			if (arr[i] != arr[i - 1] + 1) conti = 1;
			else
			{
				conti++;
				if (max < conti) max = conti;
			}
		}
	}

	printf("%d", max);



	system("pause");
	return 0;
}