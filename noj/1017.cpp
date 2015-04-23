/*************************************************************************
	> File Name: 1017_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/20 01:37:41 2014
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
long long dp[50][10];
long long num[50][50];
char s[50];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",&s[1]);
    memset(num,0,sizeof num);
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            num[i][j]=num[i][j-1]*10+s[j]-'0';
        }
    }
    for(int i=1;i<=n;++i){
        dp[i][0]=num[1][i];
    }
    for(int j=1;j<=k;++j){
        for(int i=2;i<=n;++i){
            for(int l=1;l<i;++l){
                dp[i][j]=max(dp[i][j],dp[l][j-1]*num[l+1][i]);
            }
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}
