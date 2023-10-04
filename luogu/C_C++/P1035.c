#include<stdio.h>
#include<stdlib.h>


int main(void) {
	
	int n = 0;
	double k;
	scanf("%lf", &k);
	double sum = 0;
	//printf("n=%d k=%lf\n", n, k);
	while (sum <= k)
	{
		n++;
		//printf("n=%d\n", n);
		sum += (1 / (double)n);
		//printf("sum=%f\n", sum);
	}

	printf("%d", n);

	system("pause");
	return 0;
}