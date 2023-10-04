#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int day;
    scanf("%d", &day);
    
    int a, b;
    int sum = 0;
    int total = 0;
    for(int i=0; i<day; i++)
    {
        scanf("%d %d", &a, &b);
        sum += a+b-8;
        total += sum;
    }
    
    printf("%d\n", total);
    
    return 0;
}