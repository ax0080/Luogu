#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b);

int main(void) {
	int N, B;
    int Height[20000];
    int count=0, sum=0;

    scanf("%d %d",&N, &B);
    for(int i=0; i<N; i++)
    {
        scanf("%d", Height+i); 
    }

    qsort(Height, N, sizeof(int), cmpfunc);
/*
    for(int i=0; i<N; i++)
    {
        printf("%d", Height[i]); 
    }
*/ 
    
    while(sum < B)
    {
        sum += Height[count];
        count++;
    }
    printf("%d", count);
	return 0;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}