#include<stdio.h>
#include<stdlib.h>

void bubble(long long int* arr);
void swap(long long int* a, long long int* b);
long long int gcd(long long int a, long long int b);

int main(void) {
	
	long long int num[3];
	scanf("%lld %lld %lld", num, num + 1, num + 2);
	bubble(num);
	//printf("%lld %lld %lld\n", *num, *(num + 1), *(num + 2));
	long long int gcdd = gcd(num[0], num[2]);
	printf("%lld/%lld", num[0] / gcdd , num[2] / gcdd);

	system("pause");
	return 0;
}

void bubble(long long int* arr)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j > 0; j--)
		{
			if (*(arr + j) < *(arr + j - 1)) swap(arr + j, arr + j - 1);
		}
	}
}

void swap(long long int* a, long long int* b)
{
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

long long int gcd(long long int a, long long int b)
{
	if (a == 0) return b;
	else if (a >= (b - a)) return gcd(b - a, a);
	else return gcd(a, b - a);
}