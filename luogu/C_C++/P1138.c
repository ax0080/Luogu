#include <stdio.h>
#include <algorithm>
using namespace std;
int n,tot,k;
int a[10010];
bool f[30010];
int search_k(int l,int r)
{
    if(l==r&&l==k) return a[k];
    if(l<r)
    {
        int i=l,j=r,p=a[l]; 
        while(i<j)
        {
            while(i<j&&a[j]>p) j--; 
            if(i<j) swap(a[i],a[j]);
            while(i<j&&a[i]<=p) i++;
            if(i<j) swap(a[i],a[j]);
        }
        a[i]=p;
        if(i==k) return a[k];
        else if(i>k) return search_k(l,i-1); 
        else return search_k(i+1,r); 
    }
}
int main()
{
    int x;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(!f[x]){
            a[++tot]=x;
            f[x]=true;
        }
    }
    if(tot<k) {printf("NO RESULT");return 0;}
    printf("%d",search_k(1,tot));
    return 0;
}