/*************************************************************************
	> File Name: 1703.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  1/26 08:05:06 2015
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
#define SIZE 100010
int dsu[SIZE];
int Rank[SIZE];
void init(int n){
    for(int i=1;i<=n;++i){
        dsu[i]=i;
        Rank[i]=0;
    }
}
int find_(int p){
    int x=p;
    if(dsu[p]==p) return p;
    x=find_(dsu[p]);
    Rank[p]=Rank[p]^Rank[dsu[p]];
    return dsu[p]=x;
}
void make_union(int x,int y){
    int fx=find_(x);
    int fy=find_(y);
    if(fx==fy) return;
    dsu[fx]=fy;
    Rank[fx]=~(Rank[y]^Rank[x]);
}
int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T--){
        scanf("%d%d",&n,&m);
        init(n);
        while(m--){
            char c[2];
            int a,b;
            scanf("%s%d%d",c,&a,&b);
            if(c[0]=='A'){
                if(n==2) printf("In different gangs.\n");
                else{
                    if(find_(a)==find_(b)){
                        if((Rank[a]-Rank[b])&1) printf("In different gangs.\n");
                        else printf("In the same gang.\n");
                    }
                    else printf("Not sure yet.\n");
                }   
            }
            else make_union(a,b);
        }
    }
    return 0;
}
