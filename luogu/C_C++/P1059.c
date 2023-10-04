#include <stdio.h>

int final[1000] = {0};

int bubble(int N, int num[]);
void swap(int *a, int *b);

int main(void) {
  
    int num[1000] = {0};
    int N;
    
    scanf("%d" ,&N);
    int pos;
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &pos);
        num[pos-1] = 1;
    }
    
    int sum = bubble(N, num);
    printf("%d\n", sum);
    for(int i=0; i<sum; i++)
    {
        printf("%d ", *(final+i));
    }
    
    return 0;
}

int bubble(int N, int num[])
{
    int sum = 0;
    for(int i=0; i<1000; i++)
    {
        if(num[i]==1)
        {
            final[sum] = i + 1;
            sum++;
        }
    }
    
    for(int i=0; i<sum; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(final[j] < final[j-1])
                swap(final+j, final+j-1);
        }
    }
    
    return sum;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b =temp;
}