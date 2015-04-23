/*************************************************************************
	> File Name: fu3+1.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 01:54:31 2014
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
    int n;
    while(scanf("%d", &n)!=EOF) {
        int i;
        long long res=0, n1=0, n2=0, n3=0;
        for(i=0; i<n; i++) {
            int num;
            scanf("%d", &num);
            n3 += num/3;
            if(num%3 == 1)
                n1++;
            if(num%3 == 2)
                n2++;
        }
        if(n3 == 0) {
            printf("0\n");
        } else {
            res += n2;
            if(n1 > n3 - 1)
                res += (2*n3 - 1);
            else {
                res += 2*n1 + (n3-n1-1)/2*3;
                if((n3-n1)%2 == 0)
                    res += 2;
                else
                    res += 1;
            }
            printf("%lld\n", res);
        }
    }

    return 0;
}
