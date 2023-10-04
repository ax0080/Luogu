#include <stdio.h>
#include <stdlib.h>


int main(void) {
    
    int num;
    scanf("%d", &num);
    
    double arr[48];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<num; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    printf("%.2lf", arr[num-1]);
    
    
    
    return 0;
}