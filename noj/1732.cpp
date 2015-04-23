/*************************************************************************
	> File Name: 1732.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  2/ 3 09:07:20 2015
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
const int maxn=100000;
bool isprime[maxn+10];
int prime[maxn+10];
int cnt=0;
void init(){
    memset(isprime,true,sizeof isprime);
    memset(prime,0,sizeof prime);
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=maxn;++i){
        if(isprime[i]){
            for(int j=i+i;j<=maxn;j+=i){
                if(isprime[j]) isprime[j]=false;
            }
        }
    }
    for (int i=2;i<=maxn;++i){
        if(isprime[i]){
            prime[cnt]=i;
            ++cnt;
        }
    }
}
int n;
bool judge(int x){
    if(x<=maxn){
        return isprime[x];
    }
    else {
        for(int i=0;prime[i]*prime[i]<=x;++i){
            if(x%prime[i]==0) return false;
        }
        return true;
    }
}
void dfs(int step,int value){
    if(step==n){
        printf("%d\n",value);
    }
    else{
        if(step==0){
            for(int i=0;i<4;++i){
                dfs(step+1,prime[i]);
            }
        }
        else {
            value*=10;
            for(int i=0;i<10;++i){
                if(judge(value+i)){
                    dfs(step+1,value+i);
                } 
            }
        }
    }
}
int main(){
    init();
    while(~scanf("%d",&n))
        dfs(0,0);
    return 0;
}
