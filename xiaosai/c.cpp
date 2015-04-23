/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 09:26:22 2015
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
long long mod=1000000007;
long long qpow(long long x,long long n){
    long long res=1;
    x%=mod;
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
long long x,n;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&x,&n);
        printf("%I64d\n",qpow(x,n));
    }
    return 0;
}
