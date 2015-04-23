/*************************************************************************
	> File Name: 2080.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/31 09:17:42 2015
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
int rudu[505];
bool g[505][505];
bool vis[505];
queue <int> q;
int main(){
    ios::sync_with_stdio(false);
    string s1,s2;
    int n;
    while(~scanf("%d",&n)){
        int cnt=1;
        map<string,int> mp;
        memset(rudu,0,sizeof rudu);
        memset(g,false,sizeof g);
        memset(vis,false,sizeof vis);
        while(!q.empty()) q.pop();
        for(int i=0;i<n;++i){
            cin>>s1>>s2;
            if(!mp[s1]){
                mp[s1]=cnt++;
            }
            if(!mp[s2]){
                mp[s2]=cnt++;
            }
            g[mp[s1]][mp[s2]]=true;
            rudu[mp[s1]]++;
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            string s;
            cin>>s;
            vis[mp[s]]=true;
        }
        int ans=0;
        for(int i=1;i<cnt;++i){
            if(rudu[i]==0){
                q.push(i);       
            }
        }
        while(!q.empty()){
            int k=q.front();
            q.pop();
            if(vis[k]){
                ++ans;
                vis[k]=false;
            }
            //++ans;
            for(int i=1;i<cnt;++i){
                if(g[k][i]){
                    g[k][i]=false;
                    --rudu[i];
                    if(rudu[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        if((double)ans/(double)m>0.7)
        {
            puts("Excelsior!");
        }
        else{
            puts("KSS have a dream!");
        }
    }
    return 0;
}
