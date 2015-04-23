/*************************************************************************
	> File Name: 1232.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  1/26 15:59:02 2015
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
int dsu[1010];
void init(int n){
    for(int i=1;i<=n;++i){
        dsu[i]=i;
    }
}
int find_(int x){
    int k=x;
    while(dsu[x]!=x){
        x=dsu[x];
    }
    while(dsu[k]!=k){
        int tmp=k;
        k=dsu[k];
        dsu[k]=x;
    }
    return x;
}
void make_union(int x,int y){
    int a=find_(x);
    int b=find_(y);
    int min=a<b?a:b;
    dsu[a]=dsu[b]=min;
}
int main(){
    int n,m;
    while(scanf("%d",&n),n){
        init(n);
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            make_union(x,y);
        }
        int ans=0;
        for(int i=2;i<=n;++i){
            if(find_(i)!=find_(1)){
                ++ans;
                make_union(i,1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
