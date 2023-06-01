#include<stdio.h>
#include<stdlib.h>


int main(void) {
	
	int flag = 0;
	int k;
	scanf("%d", &k);

	for (int i = 10000; i <= 30000; i++)
	{
		int sub1 = i/100;
		int sub2 = (i / 10) % 1000;
		int sub3 = i % 1000;

		if ((sub1 % k) == 0 && (sub2 % k) == 0 && (sub3 % k) == 0)
		{
			flag = 1;
			printf("%d\n", i);
		}
	}

	if (flag == 0) printf("No\n");

	system("pause");
	return 0;
}