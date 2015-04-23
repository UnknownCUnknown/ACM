/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 18:34:11 2015
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
bool vis[100];
int len[100];
int n;
int sum,side;
int Max=0;
bool flag1=false;
int target=0;

void dfs(int le,int now,int num){
    if(le==side) {
        dfs(0,0,num+1);
    }
    if(num==target){
        flag1=true;
        return;
    }
    if(le>side){
        return;
    }
    if(flag1) return;
    for(int i=now;i<n;++i){
        if(flag1) return;
        if(i&&!vis[i-1]&&len[i]==len[i-1]) continue;
        if(!vis[i]&&le+len[i]<=side){
            vis[i]=true;
            dfs(le+len[i],i+1,num);
            if(flag1) return;
            vis[i]=false;
            if(le==0) return;
        }
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    while(scanf("%d",&n),n){
        sum=0;
        Max=0;
        for(int i=0;i<n;++i){
            scanf("%d",len+i);
            if(len[i]>Max) Max=len[i];
            sum+=len[i];
        }
        sort(len,len+n,cmp);
        flag1=false;
        memset(vis,false,sizeof(vis));
        for(int i=Max;i<=sum;++i){  
            if(sum%i==0){
                target=sum/i;
                side=i;
                dfs(0,0,0);
                if(flag1){
                    break;
                }
                else {
                    memset(vis,false,sizeof vis);
                }
            }
        }
        printf("%d\n",side);
    }
    return 0;
}


