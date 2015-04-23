/*************************************************************************
	> File Name: 2.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/ 9 13:47:48 2015
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
struct Point{
    int x,y,z;
    Point(){
        x=y=z=0;
    }
};
int sumx[25],sumy[25],sumz[25];
Point p[25];
bool vis[25];
Point G;
bool flag;
int num;
void dfs(Point now,int col){
    if(now.x==G.x&&now.y==G.y&&now.z==G.z){
        flag=true;
        return ;
    }
    if(now.x>G.x||now.y>G.y||now.z>G.z){
        return ;
    }
    for(int k=col;k<num;++k){
        if(now.x+sumx[k]<G.x||now.y+sumy[k]<G.y||now.z+sumz[k]<G.z) return;
        if(!vis[k]){
            vis[k]=true;
            Point tmp;
            tmp.x=now.x+p[k].x;
            tmp.y=now.y+p[k].y;
            tmp.z=now.z+p[k].z;
            dfs(tmp,col);
            vis[k]=false;
        }
        if(flag) break;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        scanf("%d%d%d",&G.x,&G.y,&G.z);
        scanf("%d",&num);
        for(int i=0;i<num;++i){
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        }
        sumx[num]=sumy[num]=sumz[num]=0;
        for(int i=num-1;i>=0;--i){
            sumx[i]=sumx[i+1]+p[i].x;
            sumy[i]=sumy[i+1]+p[i].y;
            sumz[i]=sumz[i+1]+p[i].z;
        }
        memset (vis,false,sizeof vis);
        Point s;
        flag=false;
        dfs(s,0);
        printf("Case #%d: ",ca);
        if(flag){
            printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}
