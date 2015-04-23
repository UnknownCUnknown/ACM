/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  3/ 2 15:12:35 2015
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
long long mod=1e9+7;
long long qpow(long long x,long long n){
    long long result=1;
    while(n){
        if(n&1){
            result*=x;
            result%=mod;
        }
        x*=x;
        x%=mod;
        n=n/2;
    }
    return result;
}
char s[100010];
int haha[300];
int a[5];
int main(){
    int n;
    scanf("%d",&n);
    memset(haha,0,sizeof haha);
    int cnt=0;
    scanf("%s",s);
    for(int i=0;i<n;++i){
        ++haha[s[i]];
    }
    a[0]=haha['A'];
    a[1]=haha['G'];
    a[2]=haha['C'];
    a[3]=haha['T'];
    sort(a,a+4);
    long long ans;
    if(a[3]>a[2]){
        ans=1;
    }
    else if(a[2]>a[1]){
        ans=qpow(2,n);
    }
    else if(a[1]>a[0]){
        ans=qpow(3,n);
    }
    else {
        ans=qpow(4,n);
    }
    printf("%I64d\n",ans);
    return 0;
}
