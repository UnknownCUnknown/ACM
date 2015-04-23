/*************************************************************************
	> File Name: d_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三 12/31 01:04:31 2014
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
#define N 100010

struct E{
    int a,b,c;
    void read(){
        scanf("%d%d%d",&a,&b,&c);
    }
}es[N];
int n;
vector<int> e[N];
bool vis[N];
int dep[N],sz[N];
int go(int p,int lv){
    vis[p]=1;
    dep[p]=lv;
    sz[p]=1;
    for(auto it=e[p].begin();it!=e[p].end();++it){
        auto &ee=es[*it];
        int to=p^ee.a^ee.b;
        if(vis[to]) continue;
        sz[p]+=go(to,lv+1);
    }
    return sz[p];
}
double f(double x){
    return x*(x-1)/2.0;
}
double z[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i) es[i].read();
    for(int i=1;i<=n-1;++i){
        e[es[i].a].push_back(i);
        e[es[i].b].push_back(i);
    }
    go(1,1);
    for(int i=1;i<=n-1;++i){
        int a=es[i].a;
        int b=es[i].b;
        if(dep[a]>dep[b]) swap(a,b);
        int x=sz[b],y=n-x;
        z[i]=2*(f(x)*y+f(y)*x);
    }
    double base=1.0*n*(n-1)*(n-2)/6.0;
    double s=0;
    for(int i=1;i<=n-1;++i) s+=z[i]*es[i].c;
    int q;
    scanf("%d",&q);
    while(q--){
        int i,c;
        scanf("%d%d",&i,&c);
        s-=z[i]*es[i].c;
        es[i].c=c;
        s+=z[i]*es[i].c;
        printf("%.9f\n",s/base);
    }
    return 0;
}

