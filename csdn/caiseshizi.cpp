/*************************************************************************
	> File Name: caiseshizi.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 20:49:44 2014
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

#define rep(i,s,t) for(int i=s;i<t;i++)
#define repp(i,s,t) for(int i=s-1;i>=t;i--)
#define clr(a) memset(a,0,sizeof(a));

int n,k;
int dp[111][111],a[7],x[111],y[111];
inline int get(int *a,int *b,int l){
    clr(dp);
    rep(i,1,l+1) rep(j,1,l+1){
        if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    int ans=0;
    rep(i,0,l+1) rep(j,0,l+1) ans=max(ans,dp[i][j]);
    return l-ans;
}

int main(){
    while(~scanf("%d%d",&n,&k)){
        clr(a);
        rep(i,1,n+1){
            scanf("%d",&x[i]),a[x[i]]++;
        }       
        int c[6];
        rep(i,0,k) c[i]=i+1;
        int ans=1100;
        do{
            int cnt=1;
            rep(i,0,k){
                rep(j,0,a[c[i]]){
                    y[cnt++]=c[i];
                }
            }
            ans=min(ans,get(x,y,n));
        }while(next_permutation(c,c+k));
        printf("%d\n",ans);
    }
    return 0;
}
