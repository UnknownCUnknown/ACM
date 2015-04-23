/*************************************************************************
	> File Name: 3126.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/10 11:37:31 2015
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
const int maxn=10000;
bool isprime[maxn+10];
bool vis[10000];
void init(){
    memset(isprime,true,sizeof isprime);
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=maxn;++i){
        if(isprime[i]){
            for(int j=i+i;j<=maxn;j+=i){
                if(isprime[j]) isprime[j]=false;
            }
        }
    }
}
struct prime{
    int value;
    int cnt;
    prime(){}
    prime(int a,int b){
        value=a;
        cnt=b;
    }
};
queue<prime> q;

int bit[4];
int change(){
    int re=0;
    for(int i=3;i>=0;--i){
        re*=10;
        re+=bit[i];
    }
    return re;
}
int bfs(int a,int b){
    while(!q.empty()){
        q.pop();
    }
    memset(vis,false,sizeof vis);
    vis[a]=true;
    q.push(prime(a,0));
    while(q.front().value!=b){
        int k=q.front().value;
        prime ttt=q.front();
        q.pop();
        int len=0;
        int t=k;
        vis[k]=true;
        while(t){
            bit[len++]=t%10;
            t/=10;
        }
        for(int i=0;i<4;++i){
            int tmp=bit[i];
            int be=0;
            if(i==3){
                be=1;
            }
            for(int j=be;j<=9;++j){
                bit[i]=j;
                int tmp=change();
                if(isprime[tmp]&&!vis[tmp]){
                    q.push(prime(tmp,ttt.cnt+1));
                }
            }
            bit[i]=tmp;
        }
    }
    return q.front().cnt;
}
int main(){
    int T;
    init();
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",bfs(a,b));
    }
    return 0;
}
