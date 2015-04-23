/*************************************************************************
	> File Name: 1047.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 11:59:42 2014
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
int vis[25];
int Isprint[25];
int vec[25][25];
int n,e;
bool flag=false;
int num=0;
void dfs(int now){
    if(!Isprint[now]){
        printf("%d ",now);
        Isprint[now]=1;
        ++num;
    }
    if(num==n){
        flag=true;
        return ;
    }
    if(flag) return;
    else {
        for(int i=0;i<n;++i){
            if(!vis[i]&&vec[now][i]){
                vis[i]=1;
                dfs(i);
                vis[i]=0;
            }
            if(flag) return;
        }
    }
}
int main(){
    scanf("%d%d",&n,&e);
    memset(vec,0,sizeof vec);
    for(int i=0;i<e;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        vec[a][b]=1;
        vec[b][a]=1;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n-1;++j){
            printf("%d ",vec[i][j]);
        }
        printf("%d \n",vec[i][n-1]);
    }
    memset(Isprint,0,sizeof Isprint);
    memset(vis,0,sizeof vis);
    vis[0]=1;
    for(int i=0;i<n;++i){
        if(!Isprint[i]){
            dfs(i);
        }
    }
    printf("\n");
    return 0;
}
