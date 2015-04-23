/*************************************************************************
	> File Name: xunhuancishu.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 02:00:00 2014
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
long long pow2[33];

void init() {
    pow2[0] = 1;
    for(int i=1; i<=32; i++)
        pow2[i] = pow2[i-1] * 2;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    } 
    else {
        long long res = exgcd(b, a%b, x, y);
        long long t = x;
        x = y;
        y = t - a/b * y;
        return res;
    }
}
int main() {
    init();
    long long a, b, c, k;
    while(scanf("%lld%lld%lld%lld", &a, &b, &c, &k)!=EOF) {
        long long x, y;
        long long gcd = exgcd(pow2[k], c, y, x);
        if((b-a)%gcd != 0) {
            printf("-1\n");
        } else {
            x = x * ((b - a) / gcd);
            if(x >= 0)
                printf("%lld\n",  x%(pow2[k]/gcd));
            else {
                printf("%lld\n", pow2[k]/gcd - (-x)%(pow2[k]/gcd));
            }
        }
    }
    return 0;
}        

