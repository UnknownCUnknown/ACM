/*************************************************************************
	> File Name: csdn2.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/10 16:29:04 2015
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
struct skill{
    int peo;
    int tt;
    skill(){}
    skill(int a,int b){
        peo=a;
        tt=b;
    }
};
bool cmp(skill a,skill b){
    return a.tt<b.tt;
}
skill s[10010];
int n,m;
bool vis[110];
int v[110];
int main(){
    while(~scanf("%d%d",&n,&m)){
        int cnt=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                s[cnt].peo=i;
                scanf("%d",&s[cnt++].tt);
            }
        }
        sort(s,s+cnt,cmp);
        int l=0,r=0;
        int num=0;
        memset(vis,false,sizeof vis);
        memset(v,0,sizeof v);
        int ans=1000000011;
        while(l<cnt){
            while(r<cnt&&num!=n){
                if(v[s[r].peo]==0){
                    ++num;
                }
                ++v[s[r].peo];
                ++r;
            }
            if(num!=n){
                break;
            } 
            else{
                if(s[r-1].tt-s[l].tt<ans){
                    ans=s[r-1].tt-s[l].tt;
                }
                --v[s[l].peo];
                if(v[s[l].peo]==0){
                    --num;
                }
                ++l;
            }
        }
        printf("%d\n",ans);
    }   
    return 0;
}
