/*************************************************************************
	> File Name: 2089.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/ 8 18:41:50 2015
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
int dp[10][4];
//dp[i][0]表示i位数中满足条件的数的个数
//dp[i][1]表示i位数中满足条件的以2开头的数的个数
//dp[i][2]表示i位数中不满足条件的数的个数
void init(){
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<=7;++i){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]*10;
        //printf("%d\n",dp[i][0]+dp[i][2]);
    }
}
int solve(int n){
    int tmp=n;
    int len=0,bit[10];
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    bit[len+1]=0;
    int ans=0;
    bool flag=false;
    for(int i=len;i>0;--i){
        ans+=dp[i-1][2]*bit[i];
        if(flag){
            ans+=dp[i-1][0]*bit[i];
        }
        if(!flag&&bit[i]>4){
            ans+=dp[i-1][0];
        }
        if(!flag&&bit[i+1]==6&&bit[i]>2){
            ans+=dp[i][1];
        }
        if(!flag&&bit[i]>6){
            ans+=dp[i-1][1];
        }
        if(bit[i]==4||(bit[i+1]==6&&bit[i]==2)){
            flag=true;
        }
    }
    return tmp-ans;
}
int main(){
    int l,r;
    init();
    while(~scanf("%d%d",&l,&r)&&l+r){
        printf("%d\n",solve(r+1)-solve(l));
    }
    return 0;
}
