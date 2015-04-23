/*************************************************************************
	> File Name: 277A.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/10 13:46:26 2015
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
int dsu[110];
void init(int n){
    for(int i=1;i<=n;++i){
        dsu[i]=i;
    }
}
int find_(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=find_(dsu[x]);
}
void make_union(int x,int y){
    int a=find_(x);
    int b=find_(y);
    int m=min(a,b);
    dsu[a]=dsu[b]=m;
}
bool lan[110][110];
bool cnt[110];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    memset(lan,false,sizeof lan);
    int sum=0;
    for(int i=1;i<=n;++i){
        int num;
        scanf("%d",&num);
        sum+=num;
        int tmp;
        for(int j=0;j<num;++j){
            scanf("%d",&tmp);
            lan[i][tmp]=true;
        }
    }
    for(int i=1;i<=m;++i){
        int be=1;
        while(be<=n&&!lan[be][i]){
            ++be;
        }
        for(int j=be;j<=n;++j){
            if(lan[j][i]){
                make_union(be,j);
            }
        }
    }
    int ans=0;
    if(sum==0){
        printf("%d\n",n);
    }
    else{
        memset(cnt,false,sizeof cnt);
        for(int i=1;i<=n;++i){
            int tmp=find_(i);
            if(!cnt[tmp]){
                cnt[tmp]=true;
                ++ans;
            }
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
