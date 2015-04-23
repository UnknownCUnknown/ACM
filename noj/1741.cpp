/*************************************************************************
	> File Name: 1741.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 12:03:29 2015
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
const int maxn=1000;
int S[1100][1100];
const int mod=2011;
void init(){
    for(int n=0;n<=maxn;++n){
        for(int k=0;k<=n;++k){
            if(k==0) S[n][k]=0;
            else if(n==k||k==1) S[n][k]=1;
            else S[n][k]=S[n-1][k-1]+k*S[n-1][k];
            S[n][k]%=mod;
        }
    }
}
int main(){
    int n;
    init();
    while(~scanf("%d",&n)){
        int ans=0;
        int sign=1;
        for(int i=1;i<=n;++i){
            sign*=i;
            sign%=mod;
            ans+=sign*S[n][i]%mod;
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
