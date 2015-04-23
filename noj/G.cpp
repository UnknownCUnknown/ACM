/*************************************************************************
	> File Name: G.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/16 15:53:51 2015
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
int rudu[1010];
bool vis[1010];
int M,C;
stack<int> s1,s2;
vector<int> v[1010];
int main(){
    while(scanf("%d%d",&M,&C)&&(M!=0||C!=0)){
        memset(rudu,0,sizeof rudu);
        memset(vis,false,sizeof vis);
        for(int i=1;i<=M;++i) v[i].clear();
        for(int i=0;i<C;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            ++rudu[b];
        }
        int flag=0;
        int cnt=0;
        while(1){
            for(int i=1;i<=M;++i){
                if(!vis[i]&&rudu[i]==0){
                    s1.push(i);
                } 
            }
            int size=s1.size();
            if(s1.size()>1){
                flag=1;
            }
            if(s1.size()==0) break;
            while(!s1.empty()){
                int tmp=s1.top();
                vis[tmp]=true;
                int ss=v[tmp].size();
                for(int i=0;i<ss;++i){
                    --rudu[v[tmp][i]];
                }
                ++cnt;
                s1.pop();
            }
        }
       // printf("%d\n",cnt);
        if(cnt!=M){
            printf("Wrong Results\n");
        }
        else if(flag){
            printf("Competition continue\n");
        }
        else {
            printf("Competition over\n");
        }
    }
    return 0;
}
