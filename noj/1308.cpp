/*************************************************************************
	> File Name: 1308.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  1/ 4 19:24:28 2015
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
int v[20];
int w[20];
int dp[20];
bool ans[20][20];
bool use[20];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<2;++i){
        for(int j=1;j<=n;++j){
            if(i==0){
                scanf("%d",v+j);
            }
            else {
                scanf("%d",w+j);
            }
        }
    }
    memset (dp,0,sizeof dp);
    memset (use ,false, sizeof use);
    memset (ans, false ,sizeof ans);
    for(int i=1;i<=n;++i){
        for(int j=m;j>=0;--j){
            if(j>=w[i]){
                if(dp[j]<dp[j-w[i]]+v[i]){
                    dp[j]=dp[j-w[i]]+v[i];
                    ans[dp[j]][i]=1;
                }
            }
        }
    }
    printf("%d\n",dp[m]);
    int M=dp[m];
    for(int i=n;i>=1;--i){
        if(ans[M][i]==1){
            use[i]=1;
            M-=v[i];
        }
        else use[i]=0;
    }
    for(int i=1;i<n;++i){
        printf("%d ",use[i]);
    }
    printf("%d\n",use[n]);
    return 0;
}
