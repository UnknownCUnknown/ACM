/*************************************************************************
	> File Name: 2debuma.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 01:47:58 2014
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
long long pow2[32];
long long work(unsigned int num) {
    int k = 0, pos = 0;
    int onePosition[32];
    unsigned int t = num;
    while(t != 0) {
        if((t&1) == 1) {
            onePosition[k++] = pos;
        }
        t >>= 1;
        pos++;
    }
    k--;
    long long res = 0;
    while(k >= 0) {
        res += pow2[onePosition[k]]/2 * onePosition[k];
        num = (num&(~(1<<onePosition[k])));
        res += num + 1;
        k--;
    }
    return res;
}
void init() {
    pow2[0] = 1;
    for(int i=1; i<32; i++)
        pow2[i] = pow2[i-1] * 2;
}
int oneBNum(unsigned int num) {
    int res = 0;
    while(num != 0) {
        if(num%2 == 1)
            res++;
        num >>= 1;
    }
    return res;
}
int main() {
    init();
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        if(a >= 0 && b >= 0) {
            printf("%lld\n", work(b) - work(a) + oneBNum(a));
        }
        if(a < 0 && b >= 0) {
            printf("%lld\n", work(b) + work(0xffffffff) - work(a) + oneBNum(a));
        }
        if(a < 0 && b < 0) {
            printf("%lld\n", work(b) - work(a) + oneBNum(a));
        }
    }
    return 0;
}
