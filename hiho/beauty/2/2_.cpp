/*************************************************************************
	> File Name: 2_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  4/17 10:32:59 2015
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
#define MAXN 1010
#define ll long long
long long mod = 100007;
char s[MAXN];
ll dp[MAXN][MAXN];
int main()
{
    int cas;
    scanf("%d",&cas);
    for (int ca = 1;ca <= cas ;++ca)
    {
        scanf("%s",s);
        int n=strlen(s);
        for(int len=0;len<n;len++)
            for(int i=0;i<n;i++)
            {
                int j=i+len;
                if(j>=n) break;
                
                if(s[i]==s[j])
                {
                    dp[i][j]=1;
                    int l=i+1,r=j-1;
                    if(l<=r)
                        dp[i][j]+=dp[l][r];
                    dp[i][j] %= mod;
                }
                else
                    dp[i][j]=0;

                if(i!=j)
                {
                    dp[i][j]+=dp[i+1][j]+dp[i][j-1];
                    dp[i][j] %= mod;
                    int l=i+1,r=j-1;
                    if(l<=r)
                        dp[i][j]=dp[i][j] + mod - dp[l][r];
                    dp[i][j] %= mod;
                }
            }
        printf("Case #%d: %lld\n",ca,dp[0][n-1]);
    }
    return 0;
}
