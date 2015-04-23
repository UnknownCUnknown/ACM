/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  4/ 3 18:36:18 2015
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
int dp[25][5];
int a[25][5];
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            for(int j=0;j<3;++j){
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof dp);
        for(int i=0;i<3;++i){
            dp[0][i]=a[0][i];
        }
        int ans=0;
        for(int i=1;i<n;++i){
            dp[i][0]=a[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=a[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=a[i][2]+min(dp[i-1][0],dp[i-1][1]);
            if(i==n-1){
                ans=min(min(dp[i][0],dp[i][1]),dp[i][2]);
            }
        }
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
