/*************************************************************************
	> File Name: csdn.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/10 15:14:38 2015
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
int dp[110][110][110];
int gcd(int a,int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    else return gcd(a%b,b);
}
int mod=1000000007;
int main(){
    memset(dp,0,sizeof dp);
    for(int i=1;i<=105;++i){
        dp[i][1][i]=1;
        dp[i][i][1]=1;
    }
    for(int j=1;j<=104;++j){
        for(int i=j;i<=105;++i){
            for(int k=1;k<=105;++k)
            {
                if(dp[i][j][k]==0) continue;
                for(int tryi=i+1;tryi<=105;++tryi){
                    if(tryi==j+1) continue;
                    int tmp=gcd(k,tryi-i);
                    if(tmp==tryi) continue;
                    dp[tryi][j+1][tmp]+=dp[i][j][k];
                    dp[tryi][j+1][tmp]%=mod;
                }
            }   
        }
    }
    //for(int i=1;i<=105;++i){
        //for(int j=1;j<=i;++j){
            //printf("%d %d %d\n",i,j,dp[i][j][1]);
        //}
    //}
    int m,n;
    //for(int i=1;i<=105;++i){
        //for(int j=1;j<=i;++j){
            //printf("%d ",dp[i][j][1]);
        //}
        //printf("\n");
    //}
    while(~scanf("%d%d",&m,&n)){
        printf("%d\n",dp[m][n][1]);
    }
    return 0;
}
