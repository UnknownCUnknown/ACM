/*************************************************************************
	> File Name: 2.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  4/17 09:59:00 2015
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
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;
char s1[1010];
char s2[1010];
long long mod = 100007;
long long dp[1010][1010];
long long qpow(long long x,long long n){
    long long res = 1;
    while (n){
        if(n&1){
            res = res * x % mod;
        }
        x = x * x % mod;
        n = n >> 1;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca = 1;ca <= T;++ca){
        scanf("%s",s1);
        int len = strlen(s1);
        for(int i = 0;i < len ;++i){
            s2[len-1-i] = s1[i];
        }
        s2[len] = '\0';
        memset(dp,0,sizeof dp);
        dp[0][0] = (s1[0] == s2[0]? 1:0);
        for (int j = 1; j < len ;++j){
            dp[0][j] = dp[0][j-1];
            if (s1[0] == s2[j]){
                ++dp[0][j];
                dp[0][j] %= mod;
            }
            printf ("i=%d j=%d dp[i][j]=%lld\n",0,j,dp[0][j]);
        }
        for (int i = 1; i < len ;++i){
            for (int j = 0 ; j < len ; ++j){
                if(j == 0){
                    dp[i][j] = dp[i-1][j];
                    if (s1[i] == s2[j]){
                        dp[i][j] += dp[i-1][j] + 1;
                        dp[i][j] %= mod;
                    }
                    printf ("i=%d j=%d dp[i][j]=%lld\n",i,j,dp[i][j]);
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                if(s1[i] == s2[j]){
                    dp[i][j] += dp[i-1][j-1] + 1;
                    dp[i][j] %= mod;
                }    
                printf ("i=%d j=%d dp[i][j]=%lld\n",i,j,dp[i][j]);
            }
        }
        printf("%lld\n",dp[len-1][len-1]);
        //printf ("%lld\n",dp[len-1][len-1] * qpow(2,mod-2) % mod);
    }
    return 0;
}
