/*************************************************************************
	> File Name: 1042.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/20 02:02:49 2014
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
const int MAXN=50010;
int dp[MAXN][20];
int mm[MAXN];
int n;
int b[10010];
void initRMQ(){
    mm[0]=-1;
    for(int i=1;i<=n;++i){
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        dp[i][0]=b[i];
    }
    for(int j=1;j<=mm[n];++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int rmq(int x,int y){
    int k=mm[y-x+1];
    return min(dp[x][k],dp[y-(1<<k)+1][k]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",b+i);
    }
    initRMQ();
    int m;
    scanf("%d",&m);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",rmq(x,y));
    }
    return 0;
}
