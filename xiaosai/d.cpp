/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 09:41:08 2015
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
int n,m;
int li;
char mpp[25][25];
bool vis[25][25];
int bex,bey;
int enx,eny;
bool flag;
int row[]={-1,0,0,1};
int col[]={0,-1,1,0};
bool judge(int x,int y){
    if(x<0||y<0) return false;
    if(x>=n||y>=m) return false;
    if(mpp[x][y]=='*') return false;
    if(vis[x][y]) return false;
    return true;
}
void dfs(int x,int y,int step){
    //printf("%d %d\n",x,y);
    if(mpp[x][y]=='O'){
        flag=true;
        return ;
    }
    if(step==li){
        return ;
    }
    for(int i=0;i<4;++i){
        int tmpx = x+row[i];
        int tmpy = y+col[i];
        if(judge(tmpx,tmpy)){
            vis[tmpx][tmpy]=true;
            dfs(tmpx,tmpy,step+1);
            if(flag) {
                return ;
            }
            vis[tmpx][tmpy]=false;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&li);
        for(int i=0;i<n;++i){
            scanf("%s",mpp[i]);
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                //printf("%c",mpp[i][j]);
                if(mpp[i][j]=='X'){
                    bex=i;
                    bey=j;
                    break;
                }
            }
            //printf("\n");
        }
        memset(vis,false,sizeof vis);
        flag=false;
        vis[bex][bey]=true;
        dfs(bex,bey,0);
        if(flag){
            puts("happy end");
        }
        else{
            puts("bad end");
        }
    }    
    return 0;
}
