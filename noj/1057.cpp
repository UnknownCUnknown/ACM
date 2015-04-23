/*************************************************************************
	> File Name: 1057.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 14:31:45 2014
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
    long long n;
    scanf("%lld",&n);
    long long max=qpow(2,n);
    long long sum=0;
    long long need=max*(max+1)/2;
    for(int i=0;i<max-1;++i){
        long long tmp;
        scanf("%lld",&tmp);
        sum+=tmp;
    }
    printf("%lld\n",need-sum);
    return 0;
}
