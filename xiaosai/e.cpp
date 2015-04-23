/*************************************************************************
	> File Name: e.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 12:49:50 2015
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
int a,b;
long long n;
long long ans;
bool judge(long long k){
    while(k){
        int tmp=k%10;
        if(tmp!=a&&tmp!=b) return false;
        k/=10;
    }
    return true;
}
long long mod=1000000007;
long long qpow(long long x,long long n){
    long long res=1;
    while(n){
        if(n&1){
            res*=x;
            res%=mod;
        }
        x*=x;
        x%=mod;
        n/=2;
    }
    return res;
}
long long inv(long long i){
    return qpow(i,mod-2);
}
long long f[1000010];
void init(){
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=1000001;++i)
    {
        f[i]=f[i-1]*i;
        f[i]%=mod;
    }
}
int main(){
    init();
    while(~scanf("%d%d%I64d",&a,&b,&n)){
        long long sum;
        ans = 0;
        long long tmp;
        for(int i=0;i<=n;++i){
            sum=a*i+b*(n-i);
            if(judge(sum)){
                tmp=f[i]*f[n-i];
                tmp%=mod;
                tmp=inv(tmp);
                ans+=f[n]*tmp%mod;
                ans%=mod;
            }
            //printf("%lld\n",tmp);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
