/*************************************************************************
	> File Name: k.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 11:44:41 2015
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
int a[4];
int ans=0;
void dfs(int now,int m,int a,int b,int c,int d,bool is){
    if(now>ans) ans=now;
    if(now+m*4<ans) return ;
    if(m>=1){
        bool flag=false;
        if(b){
            if(is){
                dfs(now+4,m-1,a,b-1,c,d,true);
                flag=true;
            }
            else{
                dfs(now,m-1,a,b-1,c,d,true);
                flag=true;
            }
        }
        if(m>=2){
            if(a){
                dfs(now+3,m-2,a-1,b,c,d,true);
                flag=true;
            }
        }
        if(m>=4){
            if(c){
                dfs(now+6,m-4,a,b,c-1,d,is);
                flag=true;
            }
        }
        if(m>=10){
            if(d){
                dfs(now+10,m-10,a,b,c,d-1,is);
                flag=true;
            }
        }
        if(!flag) return ;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int m;
        scanf("%d",&m);
        for(int i=0;i<4;++i){
            scanf("%d",a+i);
        }
        ans=0;
        dfs(0,m,a[0],a[1],a[2],a[3],false);
        printf("%d\n",ans);
    }   
    return 0;
}
