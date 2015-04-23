/*************************************************************************
	> File Name: ndencifang.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 01:51:42 2014
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
char a[500001];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int i, j, k;
        scanf("%s", a);
        if(strlen(a) == 1) {
            for(i=1; i<=2; i++) {
                if(i*i == a[0]-'0')
                    break;
            }
            if(i>2)
                printf("-1\n");
            else
                printf("%d\n", i);
        } else {
            for(i=3; i<=100000; i++) {
                if((int)(i * log10((double)i)) == strlen(a) - 1)
                    break;
            }
            int res1=1;
            for(j=1; j<=i; j++) {
                res1 = (res1 * i)%11;
            }
            int res2=0, j=0;
            while(a[j] != 0) {
                res2 = (res2*10 + a[j++] - '0')%11;
            }
            if(res1 == res2)
                printf("%d\n", i);
            else
                printf("-1\n");
        }
    }

    return 0;
}

