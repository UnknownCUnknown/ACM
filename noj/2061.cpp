/*************************************************************************
	> File Name: 2061.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/14 18:32:17 2015
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
int Map[110][110];
bool vis[110][110];
int n,m,k;
int hrow[]={-1,0,1,0};
int hcol[]={0,-1,0,1};
bool judgeedge(int x,int y){
    if(x<1||y<1||x>n||y>m) return false;
    if(Map[x][y]==1) return false;
    else return true;
}
int ans=0;
bool flag;
int tarcol,tarrow;
int becol,berow;
void dfs(int col,int row,int step){
    printf("%d %d\n",col,row);
    if(step==ans){
        if(col==tarcol&&row==tarrow){
            flag=true;
        }
        return ;
    }
    for(int i=0;i<4;++i){
        int x=col+hcol[i];
        int y=row+hrow[i];
        if(judgeedge(x,y)&&!vis[x][y]){
            vis[x][y]=true;
            dfs(x,y,step+1);
            vis[x][y]=false;
        }
        if(flag) return ;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    memset(Map,0,sizeof Map);
    for(int i=0;i<k;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        Map[a][b]=1;
    }
    scanf("%d%d%d%d",&becol,&berow,&tarcol,&tarrow);
    ans=0;
    memset (vis,0,sizeof vis);
    while(ans<=n*m){
        flag=false;
        dfs(becol,berow,0);
        if(flag) break;
        ++ans;
    }
    if(flag){
        printf("%d\n",ans);
    }
    else printf("false\n");
    return 0;
}
