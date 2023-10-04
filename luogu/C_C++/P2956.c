#include<stdio.h>
#include<stdlib.h>


int main(void) {
	
	int x, y, n;
	int field[240][240];
	int x1, y1, x2, y2;
	int sum = 0;

	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 240; j++)
		{
			field[i][j] = 0;
		}
	}


	scanf("%d %d %d", &x, &y, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1 - 1; j < x2; j++)
		{
			for (int k = y1 - 1; k < y2; k++)
			{
				if (field[j][k] == 0)
					sum++;
				field[j][k] = 1;
				
			}
		}
	}

	printf("%d", sum);

	system("pause");
	return 0;
}