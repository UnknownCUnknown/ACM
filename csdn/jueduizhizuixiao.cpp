/*************************************************************************
	> File Name: jueduizhizuixiao.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 02:03:49 2014
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

inline int myMin(int a, int b) {
    return a < b ? a : b;
}

inline int myAbs(int a) {
    return a < 0 ? -a : a;
}

int array[100000];

int work(int l, int r, int num) {
    int i=l, j=r;
    while(i<=j) {
        int mid = (i+j)>>1;
        if(array[mid] > num) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    int d1 = array[i] - num;
    int d2 = num - array[j];
    return d1 < d2 ? array[i] : array[j];
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int i, j;
        for(i=0; i<n; i++)
            scanf("%d", &array[i]);
        sort(array, array+n);
        int min = myAbs(2*array[0]);
        for(i=0; i<n ; i++) {
            if(array[0] >= -array[i])
                j = array[0];
            else {
                if(array[n-1] <= -array[i])
                    j = array[n-1];
                else
                    j = work(0, n-1, -array[i]);
            }
            j = myAbs(j + array[i]);
            if(j < min)
                min = j;
        }
        printf("%d\n", min);
    }

    return 0;
}

