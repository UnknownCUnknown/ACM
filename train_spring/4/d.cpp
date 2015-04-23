/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  4/ 3 19:07:18 2015
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
int A[55];
int C[55];
int dp[1010];
int tmp[1010];
int mod=100000007;
int main(){
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int n,tar;
        scanf("%d%d",&n,&tar);
        for(int i=0;i<n;++i){
            scanf("%d",A+i);
        }
        for(int i=0;i<n;++i){
            scanf("%d",C+i);
        }
        memset(dp,0,sizeof dp);
        for(int i=0;i<=C[0];++i){
            dp[i*A[0]]=1;
        }
        for(int j=1;j<n;++j){
            memcpy(tmp,dp,sizeof dp);
            for(int k=1;k<=C[j];++k){
                for(int i=0;i<=tar;++i){
                    if(i+k*A[j]<=tar){
                        dp[i+k*A[j]]+=tmp[i];
                        dp[i+k*A[j]]%=mod;
                        //printf("%d %d %d %d\n",j,k,i+k*A[j],dp[i+k*A[j]]);
                    }
                    else{
                        break;
                    }
                }
            } 
        }
        //printf("%d\n",dp[4]);
        printf("Case %d: %d\n",ca,dp[tar]);
    }
    return 0;
}
