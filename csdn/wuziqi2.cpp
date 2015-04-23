/*************************************************************************
	> File Name: 2362.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 00:08:45 2014
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
bool vis[25];
int len[25];
int n;
int sum,a;
int Max=0;
bool flag1;
void dfs(int le,int now){
    if(le==a) {
        flag1=true;
        return;
    }
    if(le>a){
        return;
    }
    if(flag1) return;
    for(int i=now;i<n;++i){
        if(!vis[i]){
            vis[i]=true;
            dfs(le+len[i],i);
            if(flag1) return;
            vis[i]=false;
        }
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        sum=0;
        Max=0;
        for(int i=0;i<n;++i){
            scanf("%d",len+i);
            if(len[i]>Max) Max=len[i];
            sum+=len[i];
        }
        if(sum%4!=0){
            printf("no\n");
            continue;
        }
        a=sum/4;
        if(Max>a) {
            printf("no\n");
            continue;
        }
        sort(len,len+n,cmp);
        flag1=false;
        memset(vis,false,sizeof vis);
        int i;
        for(i=0;i<4;++i){
            dfs(0,0);
            if(flag1) {
                flag1=false;
            }
            else{
                break;
            }
        }
        if(i!=4) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}