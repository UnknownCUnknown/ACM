/*************************************************************************
	> File Name: 2064.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/14 18:23:39 2015
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
    cnt=0;
    for(int i=2;i<=maxn;++i){
        if(isprime[i]) prime[cnt++]=i;
    }
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<cnt;++i){
            if(isprime[n-prime[i]]){
                printf("%d %d\n",prime[i],n-prime[i]);
                break;
            }
        }
    }
    return 0;
}
