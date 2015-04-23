/*************************************************************************
 > File Name: 1011.cpp
 > Author: UnknownCUnknown
 > Mail: jsnjhcb@icloud.com
 > Created Time: 二 12/16 00:08:45 2014
 ************************************************************************/
/*
 搜索+剪枝。
 剪枝：
 1、边长必须大于等于树枝长度的最大值。
 2、将树枝长度从大到小排序，因为小的好拼。
 3、如果有一根树枝不能用，那么与它长度相同的树枝也不能用。
 4、如果在拼一条新边的时候最大的那根树枝用不上，那么就后面的必然也用不上。
 */
/*
input:
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
27
15 3 2 4 11 1 8 8 8 15 3 2 4 11 1 8 8 8 15 3 2 4 11 1 8 8 8
0
output:
6
5
20
*/
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
bool flag1;
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
        if(i&&!vis[i-1]&&len[i]==len[i-1]) continue;//剪枝3
        if(!vis[i]&&le+len[i]<=side){
            vis[i]=true;
            dfs(le+len[i],i+1,num);
            if(flag1) return;
            vis[i]=false;
            if(le==0) return;//剪枝4
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
        sort(len,len+n,cmp);//剪枝2
        flag1=false;
        memset(vis,false,sizeof(vis));
        for(int i=Max;i<=sum;++i){  //剪枝1
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

