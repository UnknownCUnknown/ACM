/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/20 18:33:28 2015
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
long long mod=7;
long long ans[1000];
long long qpow(long long x,long long n){
    long long res=1;
    x%=7;
    while(n){
        if(n&1){
            res*=x;
            res%=mod;
        }
        x*=x;
        x%=mod;
        n=n/2;
    }
    return res;
}
char s[][15]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday"};
int main(){
    long long res=0;
    ans[0]=0;
    for(int i=1;i<=300;++i){
        res+=qpow(i,i);
        res%=mod;
        ans[i]=res; 
    }
    long long n;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        n%=294;
        printf("%s\n",s[ans[n]]);
    }
    return 0;
}
