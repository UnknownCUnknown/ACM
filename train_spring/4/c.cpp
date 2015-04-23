/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  4/ 3 18:45:34 2015
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
int T;
int a[210][210];
int dp[210][210];
int main(){
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=n+1;i<=2*n-1;++i){
            for(int j=1;j<=2*n-i;++j){
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        for(int i=n+1;i<=2*n-1;++i){
            for(int j=1;j<=2*n-i;++j){
                dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
            }
        }
        printf("Case %d: %d\n",ca,dp[2*n-1][1]);
    }
    return 0;
}
