/*************************************************************************
	> File Name: dabiao.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 21:36:33 2014
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
long long C(long long n,long long m){
    if(n<m) return 0;
    if(n==m) return 1;
    if(m==0) return 1;
    long long ans=1;
    long long di=1;
    for(long long i=1;i<=m;++i){
        ans*=(n-i+1);
        di*=i;
    }
    return ans/di;
}
int main(){
    for(int n=1;n<=10;++n){
        for(int k=0;k<=n;++k){
            long long odd=n/2,even=n/2;
            if(n&1) ++odd;
            long long a=0;
            long long b=0;
            for(long long i=0;i<=k;i+=2){
                a+=C(odd,i)*C(even,k-i);
            }
            for(long long i=1;i<=k;i+=2){
                b+=C(odd,i)*C(even,k-i);
            } 
            printf("n=%d,k=%d,ans is ",n,k);
            if(a==b){
                printf("F\n");
            }
            else if(a>b){
                printf("A\n");
            }
            else {
                printf("B\n");
            }
        }
    }
    return 0;
}
