/*************************************************************************
	> File Name: 1037.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 03:14:26 2014
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
long long qpow(long long x,long long n,long long pod){
    long long result=1;
    while(n){
        if(n&1){
            result*=x;
            result%=pod;
        }
        x*=x;
        x%=pod;
        n/=2;
    }
    return result;
}
long long x,n,pod;
int main(){
    while(~scanf("%lld%lld%lld",&x,&n,&pod)){
        printf("%lld\n",qpow(x,n,pod));
    }
    return 0;
}
