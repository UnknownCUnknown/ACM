/*************************************************************************
	> File Name: 1010.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  3/18 15:26:31 2015
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
int a,b,t;
char m[10][10];
int row[]={-1,0,0,1};
int col[]={0,-1,1,0};
bool vis[10][10];
bool judge(int x,int y){
    if(x<0||y<0) return false;
    if(x>=a||y>=b) return false;
    if(m[x][y]=='X') return false;
    if(vis[x][y]) return false;
    return true;
}
bool flag;
void dfs(int step,int x,int y){
    if(flag) return;
    if(step==t){
        if(m[x][y]=='D') flag=true;
        return;
    }
    for(int i=0;i<4;++i){
        if(judge(x+row[i],y+col[i])){
            vis[x+row[i]][y+col[i]]=true;
            //cout<<x+row[i]<<" "<<y+col[i]<<endl;
            dfs(step+1,x+row[i],y+col[i]);
            vis[x+row[i]][y+col[i]]=false;
        }
        if(flag) return ;
    }
}
int main(){
    while(scanf("%d%d%d",&a,&b,&t),(a!=0||b!=0||t!=0)){
        for(int i=0;i<a;++i){
            scanf("%s",m[i]);
        }
        int bex,bey;
        int tarx,tary;
        for(int i=0;i<a;++i){
            for(int j=0;j<b;++j){
                if(m[i][j]=='D'){
                    tarx=i;
                    tary=j;
                }
                if(m[i][j]=='S'){
                    bex=i;
                    bey=j;
                }
            }
        }
        int sum=abs(tarx-bex)+abs(tary-bey);
        if(sum<t){
            puts("NO");
            continue;
        }
        if(sum&1&&t%2==0){
            puts("NO");
            continue;
        }
        if(sum%2==0&&t&1){
            puts("NO");
            continue;
        }
        flag=false;
        memset(vis,false,sizeof vis);
        vis[bex][bey]=true;
        dfs(0,bex,bey);
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
