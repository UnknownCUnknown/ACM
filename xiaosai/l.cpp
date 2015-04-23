/*************************************************************************
	> File Name: l.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 10:31:55 2015
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
int dp[400][4000];
int a[400];
int b[400];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",a+i);
        }
        for(int i=1;i<=n;++i){
            scanf("%d",b+i);
        }
        for(int j=0;j<=n;++j){
            for(int i=1;i<=3670;++i){
                dp[j][i]=400;
            }
        }
        dp[0][0]=0;
        int ans=400;
        for(int i=0;i<n;++i){
            for(int j=0;j<=10*(i+1);++j){
                //dp[i+1][j]=min(dp[i][j+b[i+1]],dp[i][j-a[i+1]]+1);
                dp[i+1][j]=dp[i][j+b[i+1]];
                if(j>=a[i+1]){
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j-a[i+1]]+1);
                }
                if(i==n-1){
                    if(dp[i+1][j]<ans){
                        ans = dp[i+1][j];
                    }
                }
            }
        }
        //printf("%d\n",dp[1][5]);
        printf("%d\n",ans);
    }
    return 0;
}
