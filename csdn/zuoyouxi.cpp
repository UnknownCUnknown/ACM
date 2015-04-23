/*************************************************************************
	> File Name: zuoyouxi.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 01:42:00 2014
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
#include <climits>

#define inf 0x7fffffff
#define MOD 1000000007
using namespace std;

inline long long myMax(long long a,long long b) {
    return a > b ? a : b;
}

long long  sum[100000];
long long array[100000];
long long dp[100000];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0){
            printf("0\n");
            continue;
        }
        int i, j;
        for(i=n-1; i>=0; i--) {
            scanf("%lld", &array[i]);
            dp[i] = 0;
        }
        sum[0] = array[0];
        for(i=1; i<n ; i++) 
            sum[i] = sum[i-1] + array[i];
        dp[0] = array[0];
        if(n > 1) dp[1] = dp[0] + array[1];
        if(n > 2) dp[2] = dp[1] + array[2];
        for(i=3; i<n; i++) {
            long long t1, t2, t3;
            t1 = array[i] + sum[i-1] - dp[i-1];
            t2 = array[i] + array[i-1] + sum[i-2] - dp[i-2];
            t3 = array[i] + array[i-1] + array[i-2] + sum[i-3] - dp[i-3];
            dp[i] = myMax(myMax(t1, t2), t3);
        }
        printf("%lld\n", dp[n-1]);
    }
    return 0;
} 
