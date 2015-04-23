/*************************************************************************
	> File Name: 2524.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  1/25 17:32:11 2015
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
int Set[50011];
void init(int n){
    for (int i=1;i<=n;++i){
        Set[i]=i;
    }
}
int find_(int i){
    int k=i;
    while(Set[k]!=k){
        k=Set[k];
    }
    while(Set[i]!=i){
        int tmp=i;
        i=Set[i];
        Set[tmp]=k;
    }
    return k;
}
void make_union(int i,int j){
    int a=find_(i);
    int b=find_(j);
    int min=a<b?a:b;
    Set[a]=Set[b]=min;
}
bool vis[50011];
int main(){
    int n,m;
    int ca=1;
    while(scanf("%d%d",&n,&m)&&(n!=0||m!=0)){
        init(n);
        memset(vis,0,sizeof vis);
        for(int i=0;i<m;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            make_union(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            int tmp=find_(i);
            //printf("%d ",tmp);
            if(!vis[tmp]){
                ++ans;
                vis[tmp]=true;
            }
        }
        //printf("\n");
        printf("Case %d: %d\n",ca,ans);
        ++ca;
    }
    return 0;
}
