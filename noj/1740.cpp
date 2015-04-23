/*************************************************************************
	> File Name: 1740.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 11:10:44 2015
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
const int maxn=500000;
bool isprime[maxn+10];
long long prime[maxn+10];
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
        if(isprime[i]) {
            prime[cnt++]=i;
        }   
    }
}
long long qpow(long long x,long long n){
    long long result=1;
    while(n){
        if(n&1){
            result*=x;
        }
        x*=x;
        n/=2;
    }
    return result;
}
int main(){
    init();
    int n;
    while(~scanf("%d",&n)){
        long long ans=1;
        int n_=n;
        for(int i=0;prime[i]*prime[i]<=n_;++i){
            if(n%prime[i]==0){
                long long ck=0;
                while(n%prime[i]==0){
                    ++ck;
                    n/=prime[i];
                }
                long long tmp=(qpow(prime[i],ck+1)-1)/(prime[i]-1);
                ans*=tmp;
                if(n==1) break;
            }
        }
        if(n!=1){
            ans*=(n+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
