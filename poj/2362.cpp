/*
 * 剪枝
 * 1:树枝的长度和为4的倍数
 * 2:树枝的长度和除以4要大于等于最长的树枝的长度
 * 3:将树枝从大到小排序
 * 4:从大到小搜索，就是选取了当前树枝之后，后面的树枝都选择比当前树枝短的
 * 5:如果当前树枝不能被选取，则与当前树枝等长的树枝也不能被选取
 * 6:如果以当前最长的没有被选取的树枝开始拼一条新边却失败了，则不可能成功。
 */
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
int sum,side;
int Max=0;
bool flag1;
void dfs(int le,int now,int num){
    if(le==side) {
        ++num;
        now=0;
        le=0;
    }
    if(num==3){
        flag1=true;
    }
    if(le>side){
        return;
    }
    if(flag1) return;
    for(int i=now;i<n;++i){//剪枝5
        if(flag1) return;
        if(i&&!vis[i-1]&&len[i]==len[i-1]) continue;//剪枝4
        if(!vis[i]){
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
        if(sum%4!=0){//剪枝1
            printf("no\n");
            continue;
        }
        side=sum/4;
        if(Max>side) {//剪枝2
            printf("no\n");
            continue;
        }
        sort(len,len+n,cmp);//剪枝3
        flag1=false;
        memset(vis,false,sizeof(vis));
        dfs(0, 0,0);
        if(!flag1) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}

