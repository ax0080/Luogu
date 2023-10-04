#include <stdio.h>

int main(void) {
    int region[10000];
    
    int l, m;
    scanf("%d %d", &l, &m);
    for(int i=0; i<=l; i++)
    {
        region[i] = 1;
    }
    
    int u, v;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &u, &v);
        for(int j=u; j<=v; j++)
        {
            region[j]=0;
        }
    }
    
    int sum=0;
    for(int i=0; i<=l; i++)
    {
        if(region[i]==1)
            sum++;
    }
    printf("%d", sum);
    return 0;
}