/*************************************************************************
	> File Name: 1652.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 20:33:03 2015
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
bool Map[10][10];
int numOfBlack;
int hcol[]={-1,0,0,1,0};
int hrow[]={0,1,-1,0,0};
bool judge(int x,int y){
    if(x<1||y<1||x>8||y>8) return false;
    else return true;
}
void ch(int x,int y){
    for(int i=0;i<5;++i){
        int m=x+hcol[i];
        int n=x+hrow[i];
        Map[m][n]=!Map[m][n];
        if(judge(m,n)){
            if(Map[m][n]) ++numOfBlack;
            else --numOfBlack;
        }   
    }
}
bool vis[10][10];
int ans=0;
bool flag;
void dfs(int step){
    if(step==ans){
        if(numOfBlack==64){
            flag=true;
            return ;
        }
    }
    else {
        for(int i=1;i<=8;++i){
            for(int j=1;j<=8;++j){
                if(!Map[i][j]&&!vis[i][j]){
                    vis[i][j]=true;
                    ch(i,j);
                    dfs(step+1);
                    ch(i,j);
                    vis[i][j]=false;
                }
                if(flag) return;
            }
        }
    }
}
char s[10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset (Map,false,sizeof Map);
        memset (vis,false,sizeof vis);
        numOfBlack=0;
        for(int i=1;i<=8;++i){
            scanf("%s",s);
            for(int j=0;j<8;++j){
                if(s[j]=='1') {
                    ++numOfBlack;
                    Map[i][j+1]=true;
                }
            }
        }
        flag=false;
        for(ans=0;ans<=64;++ans){
            dfs(0);
            if(flag) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
