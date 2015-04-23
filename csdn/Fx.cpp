/*************************************************************************
	> File Name: Fx.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 02:06:13 2014
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
const int maxn = 0x7fffffff;

int main() {
    long long n;
    while(scanf("%lld", &n) != EOF) {
        if(n == 1) {
            printf("1\n");
            continue;
        }
        long long a, b;
        long long res = 0;
        for(a=1; a*a<n; a++) {
            if(n%a == 0) {
                long long k = n/a;
                long long num = 0;
                for(b=1; b*b<k; b++) {
                    if(k%b == 0) {
                        if(b > a)
                            res++;
                        if(k/b > a)
                            res++;
                    }
                }
                if(b*b==k && b > a)
                    res++;
            }
        }
        res += res;
        for(a=1; a*a<=n; a++) {
            if(n%(a*a) == 0)
                res++;
        }
        printf("%lld\n", res);
    }

    return 0;
}
