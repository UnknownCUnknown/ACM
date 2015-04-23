/*************************************************************************
	> File Name: 1051.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  3/16 20:00:01 2015
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
struct point {
    int x,y;
};
point p[10010];
bool vis[10010];
bool cmp(point a,point b){
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmp);
        memset(vis,false,sizeof vis);
        int ans=0;
        for(int i=0;i<n;++i){
            //printf("%d %d\n",p[i].x,p[i].y);
            if(!vis[i]){
                int tmpy=p[i].y;
                vis[i]=true;
                ++ans;
                for(int j=i+1;j<n;++j){
                    if(!vis[j]){
                        if(p[j].y>=tmpy){
                            vis[j]=true;
                            tmpy=p[j].y;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
