/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  1/18 03:15:35 2015
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
const long long mod = 1000000007;
long long ans1[2010][2010];
long long ans2[2010][2010];
long long maxn=2000;
int main(){
    memset (ans1,0,sizeof ans1);
    memset (ans2,0,sizeof ans2);
    for(int i=0;i<=maxn;++i){
        ans1[0][i]=1;
        ans2[0][i]=1;
    }
    for(int i=1;i<=maxn;++i){
        for(int j=0;j<i;++j){
            if(j==0) ans1[i][j]=ans1[i-1][j];
            else ans1[i][j]=ans1[i-1][j]+ans1[i][j-1];
            ans1[i][j]%=mod;
        }
    }
    for(int i=1;i<=maxn;++i){
        for(int j=1;j<=maxn;++j){
            if(i>j) ans2[i][j]=0;
            else {
                ans2[i][j]=ans2[i-1][j]+ans2[i][j-1];
                ans2[i][j]%=mod;
            }
        }
    }
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int a,b;
        scanf("%d-%d",&a,&b);
        printf("Case #%d: %lld %lld\n",ca,ans1[a][b],ans2[b][b]);
    }
    return 0;
}
