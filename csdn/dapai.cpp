/*************************************************************************
	> File Name: dapai.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 01:35:23 2014
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
using namespace std;
int main() {
    int n1, n2, n3, n4;
    while(scanf("%d%d%d%d", &n1, &n2, &n3, &n4) != EOF) {
        if(n1==0 && n2==0) {
            printf("0\n");
            continue;
        } else {
            int t = n1+2*n2+3*n3+4*n4;
            if(t == 1 || t == 2 || t == 5) {
                printf("-1\n");
            } else {
                int res = 0;
                if(n1 <= n2) {
                    res = n1 + (n2-n1)/3 * 2;
                    n3 += n1 + (n2-n1)/3 * 2;
                    int t = (n2-n1)%3;
                    if(t == 1) {
                        if(n4 == 0)
                            res += 2;
                        else
                            res += 1;
                    } 
                    if(t == 2) {
                        res += 2;
                    }
                } else {
                    res = n2 + (n1-n2)/3*2;
                    n3 += n2 + (n1-n2)/3*2;
                    int t = (n1-n2)%3;
                    if(t == 1) {
                        if(n3 != 0)
                            res += 1;
                        else
                            res += 2;
                    }
                    if(t == 2) {
                        res += 2;
                    }
                }
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
