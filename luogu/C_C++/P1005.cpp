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
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

long long p = 1e18;

struct int128 {
    long long hig;
    long long low;
};

vector<vector<int128>> memo;  // 記憶化表格

int128 max(const int128& a, const int128& b) {
    if (a.hig > b.hig || (a.hig == b.hig && a.low > b.low)) return a;
    return b;
}

int128 operator+(const int128& a, const int128& b) {
    int128 k;
    k.low = a.low + b.low;
    k.hig = k.low / p + a.hig + b.hig;
    k.low %= p;
    return k;
}

int128 operator*(const int128& a, int b) {
    int128 k;
    k.low = a.low * b;
    k.hig = k.low / p + a.hig * b;
    k.low %= p;
    return k;
}

int128 dp_sum(int front, int back, const vector<vector<long long>>& matrix, int row, int128 sum);

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    vector<vector<long long>> matrix(n, vector<long long>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    int128 sum;
    sum.low = 0;
    sum.hig = 0;

    for (int i = 0; i < n; i++) {
        int128 sum_row;
        sum_row.low = 0;
        sum_row.hig = 0;
        sum = sum + dp_sum(0, m - 1, matrix, i, sum_row);
    }

    if (sum.hig == 0)
        printf("%lld", sum.low);
    else
        printf("%lld%018lld\n", sum.hig, sum.low);

    return 0;
}

int128 dp_sum(int front, int back, const vector<vector<long long>>& matrix, int row, int128 sum) {
    if (front == back) {
        int128 temp;
        temp.hig = 0;
        temp.low = 2 * matrix[row][front];
        return temp;
    }

    if (memo[front][back].low != -1) {
        return memo[front][back];
    }

    int128 front_first;
    int128 back_first;
    front_first.hig = 0;
    back_first.hig = 0;
    front_first.low = matrix[row][front];
    back_first.low = matrix[row][back];

    memo[front][back] = max((front_first + dp_sum(front + 1, back, matrix, row, sum)) * 2,
                            (back_first + dp_sum(front, back - 1, matrix, row, sum)) * 2);

    return memo[front][back];
}
