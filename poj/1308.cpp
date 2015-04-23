/*************************************************************************
	> File Name: 1308.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  1/27 19:10:33 2015
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
int rudu[1001];
int dsu[1001];
set <int> sv;
void init(){
    sv.clear();
    for(int i=1;i<=1000;++i){
        dsu[i]=i;
        rudu[i]=0;
    }
}
int find_(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=find_(dsu[x]);
}
void make_union(int x,int y){
    int a=find_(x);
    int b=find_(y);
    int min=a<b?a:b;
    dsu[a]=dsu[b]=min;
}
int main(){
    int n,m;
    int ca=1;
    while(scanf("%d%d",&n,&m),(n!=-1||m!=-1)){
        init();
        bool flag=true;
        if(n==0&&m==0){
            printf("Case %d is a tree.\n",ca);
            ++ca;
            continue;
        }
        else {
            make_union(n,m);
            ++rudu[m];
            if(n==m) flag=false;
            sv.insert(n);
            sv.insert(m);
            while(scanf("%d%d",&n,&m),(n!=0)){
                if(flag){
                    if(rudu[m]) flag=false;
                    if(find_(n)==find_(m)){
                        flag=false;
                    }
                    ++rudu[m];
                    make_union(n,m);
                    sv.insert(n);
                    sv.insert(m);
                }
            }
            int tmp=find_(*sv.begin());
            for (set<int>::iterator i=sv.begin();i!=sv.end();++i){
                if(tmp!=find_(*i)) flag=false;
            }
            if(flag){
                printf("Case %d is a tree.\n",ca);
            }
            else {
                printf("Case %d is not a tree.\n",ca);
            }
        }
        ++ca;
    }
    return 0;
}
