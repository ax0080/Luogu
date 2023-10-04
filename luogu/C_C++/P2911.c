#include <stdio.h>
#include <stdlib.h>

void sort(int* a, int* b, int* c);
void swap(int* a, int* b);

int main(void) {
    
    int prob[81]={0};
    int s1, s2, s3;
    scanf("%d %d %d",&s1, &s2, &s3);
    
    for(int i=1; i<=s1; i++)
    {
        for(int j=1; j<=s2; j++)
        {
            for(int k=1; k<=s3; k++)
            {
                prob[i+j+k]++;
            }
        }
    }
    
    int max=0;
    int index=0;
    for(int i=0; i<=80; i++)
    {
        if(prob[i] > max)
        {
            max = prob[i];
            index = i;
        }
    }
    
    printf("%d", index);
    
    return 0;
}