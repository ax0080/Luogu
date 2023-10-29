#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n; //number of input
    int current, next;
    int count[1001] = {0};
    int flag;

    scanf("%d", &n);
    flag = 1;

    scanf("%d %d", &current, &next);
    if( abs(next-current) < n-1 ) count[abs(next-current)] = 1;

    for(int i=0; i<n-2 ; i++)
    {
        current = next;
        scanf("%d", &next);
        if( abs(next-current) < n-1 ) count[abs(next-current)] = 1;
    }


    for(int i=1; i<n; i++)
    {
        if(count[i] == 0) flag = 0;
        break;
    }

    if(flag) printf("Jolly");
    else printf("Not jolly");
	
   
	return 0;
}