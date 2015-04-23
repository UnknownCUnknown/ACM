/*************************************************************************
	> File Name: shuxuewenti.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 01:37:46 2014
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <cstdlib>
#include <queue>
using namespace std;
#define inf 0x7fffffff
#define MOD 1000000007
using namespace std;
inline int myMin(int a, int b) {
    return a < b ? a : b;
}
inline int myMax(int a, int b) {
    return a > b ? a : b;
}
int dp[101][10001];
int a[101], b[101];
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int i, j, sum = 0;
        for(i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for(j=1; j<=n; j++)
            scanf("%d", &b[j]);
        fill_n(&dp[0][0], sizeof(dp)/sizeof(int), inf);
        dp[0][0] = 0;
        for(i=1; i<=n; i++) {
            for(j=0; j+a[i]<=sum; j++) {
                if(dp[i-1][j] != inf) {
                    dp[i][j+a[i]] = dp[i-1][j];
                } 
            }
            for(j=0; j<=sum; j++) {
                if(dp[i-1][j] != inf) {
                    dp[i][j] = myMin(dp[i][j], dp[i-1][j] + b[i]);
                }
            }
        }
        int res = inf;
        for(i=0; i<=sum; i++) {
            int t = myMax(dp[n][i], i);
            if(res > t)
                res = t;
        }
        printf("%d\n", res);
    }
    return 0;
}
