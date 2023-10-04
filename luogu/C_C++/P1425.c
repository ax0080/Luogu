#include<stdio.h>
#include<stdlib.h>


int main(void) {
	
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	int hour, minute, sum;
	sum = 60 * (c - a) + (d - b);
	
	hour = sum / 60;
	minute = sum % 60;

	printf("%d %d", hour, minute);

	system("pause");
	return 0;
}