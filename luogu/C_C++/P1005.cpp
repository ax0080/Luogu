// P1005
/*
此題中，我們可以將每一列拆開考慮，意即我們僅需求初每列各自的最大值即可。
這也被稱為，最優子結構。

本題有兩個難點
1.每個列的DP:
dp[i, j] = 2 * max(dp[i+1, j] + data[i], dp[i, j-1] + data[j])

2.後面的元素的值需和2的指數倍相乘，最後其值會非常大

*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
/*
struct int128
{
    long long hig;
    long long low;
};
int n,m;
long long p=1e18; //long long範圍
int128 ans,f[85][85][85],a[85][85];
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
*/
int dp_sum(int front, int back, int** matrix, int row, int sum);

int main() {

  int **matrix;
  int n, m;

  scanf("%d %d", &n, &m);
  matrix = new int *[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
  }

  int head;
  int tail;
  int sum = 0;
  int row_total;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) 
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    head = 0;
    tail = m - 1;
    sum += dp_sum(head, tail, matrix, i, 0);
  }


  
  printf("%d\n", sum);


  for (int i = 0; i < n; i++) 
  {
    delete[] matrix[i];
  }
  delete[] matrix;

  //printf("finish\n");

  return 0;
}

int dp_sum(int front, int back, int** matrix, int row, int sum) 
{
    int front_dp = front;
    int back_dp = back;
    

    if(front_dp == back_dp) return 2*matrix[row][front_dp];
    /*
    else if(matrix[row][front_dp] + dp_sum(front_dp+1, back_dp, matrix, row, sum) >= matrix[row][back_dp] + dp_sum(front_dp, back_dp-1, matrix, row, sum))
    {
      //printf("take %d out\n", matrix[row][front_dp]);
      sum = 2*(matrix[row][front_dp] + dp_sum(front_dp+1, back_dp, matrix, row, sum));
      //printf("sum is %d now\n", sum);
      return sum;
    }
    else
    {
      //printf("take %d out\n", matrix[row][back_dp]);
      sum = 2*(matrix[row][back_dp] + dp_sum(front_dp, back_dp-1, matrix, row, sum));
      //printf("sum is %d now\n", sum);
      return sum;
    }
    */
    else 
    {
      return std::max(2*(matrix[row][front_dp] + dp_sum(front_dp+1, back_dp, matrix, row, sum)), 2*(matrix[row][back_dp] + dp_sum(front_dp, back_dp-1, matrix, row, sum)));
    }
}
