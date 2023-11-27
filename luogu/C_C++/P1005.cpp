// P1005
/*
此題中，我們可以將每一列拆開考慮，意即我們僅需求初每列各自的最大值即可。
這也被稱為，最優子結構。

本題有兩個難點
1.每個列的DP:
dp[i, j] = 2 * max(dp[i+1, j] + data[i], dp[i, j-1] + data[j])

2.後面的元素的值需和2的指數倍相乘，最後其值會非常大，需用高精度運算

*/

#include <iostream>
#include <stdio.h>
#include <algorithm>

long long p=1e18; //long long範圍

struct int128
{
    long long hig;
    long long low;
};

int128 max(int128 a,int128 b)
{
	if(a.hig>b.hig) return a;
	if(a.hig<b.hig) return b;
	if(a.low>b.low) return a;
	if(a.low<b.low) return b;
	return a;
}
int128 operator + (int128 a,int128 b)
{
    int128 k;
    k.low=0,k.hig=0;
    k.low=a.low+b.low;
    k.hig=k.low/p+a.hig+b.hig;
    k.low%=p;
    return k;
}
int128 operator * (int128 a,int b)
{
	int128 k;
	k.low=0,k.hig=0;
	k.low=a.low*b;
	k.hig+=k.low/p+b*a.hig;
	k.low%=p;
	return k;
}

int128 dp_sum(int front, int back, long long** matrix, int row, int128 sum);

int main() {

  long long **matrix;
  int n, m;

  scanf("%d %d", &n, &m);
  matrix = new long long *[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new long long[m];
  }

  int head;
  int tail;
  int128 sum;
  sum.low = 0;
  sum.hig = 0;


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) 
    {
      scanf("%lld", &matrix[i][j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    head = 0;
    tail = m - 1;
    int128 sum_row;
    sum_row.hig = 0;
    sum_row.low = 0;
    sum = sum + dp_sum(head, tail, matrix, i, sum_row);
  }


  
  if(sum.hig==0)	printf("%lld",sum.low);
  else	printf("%lld%018lld\n",sum.hig,sum.low);


  for (int i = 0; i < n; i++) 
  {
    delete[] matrix[i];
  }
  delete[] matrix;

  //printf("finish\n");

  return 0;
}

int128 dp_sum(int front, int back, long long** matrix, int row, int128 sum) 
{
    int front_dp = front;
    int back_dp = back;
    

    if(front_dp == back_dp) 
    {
      int128 temp;
      temp.hig = 0;
      temp.low = 2*matrix[row][front_dp]; 
      return temp;
    }
    else 
    {
      int128 front_first;
      int128 back_first;
      front_first.hig = 0;
      back_first.hig = 0;
      front_first.low = matrix[row][front_dp];
      back_first.low = matrix[row][back_dp];

      return max((front_first + dp_sum(front_dp+1, back_dp, matrix, row, sum))*2, (back_first + dp_sum(front_dp, back_dp-1, matrix, row, sum))*2);
    }
}
