/*************************************************************************
	> File Name: 2492.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  1/27 16:35:05 2015
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
int dsu[2000010];
void init(int n){
    for(int i=1;i<=2*n;++i){
        dsu[i]=i;
    }
}
int find_(int x){
    if(x==dsu[x]) return x;
    else  return dsu[x]=find_(dsu[x]);
}
void make_union(int x,int y){
    int a=find_(x);
    int b=find_(y);
    int min=a<b?a:b;
    dsu[a]=dsu[b]=min;
}
int main(){
    int T;
    scanf("%d",&T);
    for (int ca=1;ca<=T;++ca){
        if(ca!=1) printf("\n");
        int n,m;
        scanf("%d%d",&n,&m);
        int flag=false;
        init(n);
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            if(!flag&&find_(a)==find_(b)) flag=true;
            else {
                make_union(a,b+n);
                make_union(a+n,b);
            }
        }
        printf("Scenario #%d:\n",ca);
        if(flag){
            printf("Suspicious bugs found!\n");
        }
        else printf("No suspicious bugs found!\n");
    }
    return 0;
}
