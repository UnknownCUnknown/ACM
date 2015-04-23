/*************************************************************************
	> File Name: f.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 10:22:36 2015
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
#include <climits>
using namespace std;
long long dp[1010][1010];
int main(){
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=1000;++i){
        for(int j=0;j<=i;++j){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=1000000007;
        }
    }
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
