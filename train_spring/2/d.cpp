/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/20 19:19:37 2015
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
int ans[20][20];
int p[20][20];
bool vis[20][20];
int row[]={-1,0,0,0,1};
int col[]={0,-1,0,1,0};
int numofone;
void flip(int x,int y){
    int tmpx;
    int tmpy;
    for(int i=0;i<5;++i){
        tmpx=x+row[i];
        tmpy=y+col[i];
        if(tmpx<=0||tmpx>n)
        {
            continue;
        }
        if(tmpy<=0||tmpy>m){
            continue;
        }
        if(p[tmpx][tmpy]==0){
            p[tmpx][tmpy]=1;
            ++numofone;
        }
        else{
            p[tmpx][tmpy]=0;
            --numofone;
        }
    }   
}
bool flag;
int tar;
int ture_ans[20][20];
void dfs(int x,int y,int step){
    if(step==tar){
        if(numofone==0){
            flag=true;
            memcpy(ture_ans,ans,sizeof ans);
        }
        return ;
    }
    if(n*m-(x-1)*n-y<tar-step) return;
    if(5*(tar-step)<numofone){
        return;
    }
    else {
        for(int i=x;i<=n;++i){
            for(int j=(i==x?y+1:1);j<=m;++j){
                if(!ans[i][j]){
                    ans[i][j]=1;
                    flip(i,j);
                    dfs(i,j,step+1);
                    ans[i][j]=0;
                    flip(i,j);
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    numofone=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&p[i][j]);
            if(p[i][j]==1){
                ++numofone;
            }
        }
    }
    for(tar=0;tar<=n*m;++tar){
        memset(vis,false,sizeof vis);
        flag=false;
        memset(ans,false,sizeof ans);
        //cout<<tar<<endl;
        dfs(0,0,0);
        if(flag) break;
    }
    
    if(flag){
        for(int i=1;i<=n;++i){
            for(int j=1;j<m;++j){
                printf("%d ",ture_ans[i][j]);
            }
            printf("%d\n",ture_ans[i][m]);
        }
    }
    else{
        puts("IMPOSSIBLE");
    }
    return 0;
}
