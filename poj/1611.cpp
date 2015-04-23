/*************************************************************************
	> File Name: 1611.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  1/25 19:07:28 2015
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
int dsu[30010];
void init(int n){
    for(int i=0;i<n;++i){
        dsu[i]=i;
    }
}
int find_(int x){
    int k=x;
    while(dsu[k]!=k){
        k=dsu[k];
    }
    while(dsu[x]!=x){
        int tmp=x;
        x=dsu[x];
        dsu[tmp]=k;
    }
    return k;
}
void make_union(int x,int y){
    int a=find_(x);
    int b=find_(y);
    int min=a<b?a:b;
    dsu[a]=dsu[b]=min;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n!=0||m!=0)){
        init(n);
        for(int i=0;i<m;++i){
            int num;
            scanf("%d",&num);
            int fi,tmp;
            if(num>0) scanf("%d",&fi);
            for(int i=1;i<num;++i){
                scanf("%d",&tmp);
                make_union(tmp,fi);
            }
        }
        int cnt=0;
        for(int i=0;i<n;++i){
            if(find_(i)==0){
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
