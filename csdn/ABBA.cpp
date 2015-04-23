/*************************************************************************
	> File Name: ABBA.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 01:57:00 2014
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
const double e = 2.718281;

int main() {
    double a, b;
    while(scanf("%lf", &a) == 1) {
        if(a > 2.718281)
            printf("-1\n");
        else {
            double l = e, r = 100;
            while(r - l >= 0.000001) {
                double mid = (l+r)/2;
                if(mid/log(mid) > a/log(a)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            printf("%.5lf\n", l);
        }
    }

    return 0;
}

