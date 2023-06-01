#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323

int main(void) {
    
    double r;
    scanf("%lf", &r);
    
    printf("%.6lf\n", r*r*PI);
    printf("%.6lf\n", 2*r*r);
    
    
    
    return 0;
}