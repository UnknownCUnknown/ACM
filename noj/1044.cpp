/*************************************************************************
	> File Name: 1044.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  2/ 3 10:45:41 2015
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
int dsu[100010];
void init(int n){
    for(int i=1;i<=n;++i){
        dsu[i]=i;
    }
}
int find_(int x){
    if(x==dsu[x]) return x;
    else return x=find_(dsu[x]);
}
void make_union(int x,int y){
    int a=find_(x);
    int b=find_(y);
    int m=min(a,b);
    dsu[a]=dsu[b]=m;
}
struct opt{
    char c[2];
    int x,y;
};
bool ans[100010];
opt o[100010];
vector<int> v[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int numo=0;
    scanf("%d",&numo);
    for(int i=0;i<numo;++i){
        scanf("%s%d%d",o[i].c,&o[i].x,&o[i].y);
        if(o[i].c[0]=='D'){
            vector<int>::iterator it=find(v[o[i].x].begin(),v[o[i].x].end(),o[i].y);
            if(it!=v[o[i].x].end()){
                v[o[i].x].erase(it);
            }       
            it=find(v[o[i].y].begin(),v[o[i].y].end(),o[i].x);
            if(it!=v[o[i].y].end()){
                v[o[i].y].erase(it);
            }       
        } 
    }
    for(int i=1;i<=n;++i){
        for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
        {
            make_union(i,*it);
        }
    }
    int cnt=0;
    for(int i=numo-1;i>=0;--i){
        if(o[i].c[0]=='D'){
            make_union(o[i].x,o[i].y);
        }
        else {
            if(find_(o[i].x)==find_(o[i].y)){
                ans[cnt]=true;    
            }
            else {
                ans[cnt]=false;
            }
            ++cnt;
        }
    }
    for(int i=cnt-1;i>=0;--i){
        if(ans[i]) puts("C");
        else puts("D");
    }
    return 0;
}
