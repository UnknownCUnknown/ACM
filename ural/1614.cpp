/*************************************************************************
	> File Name: 1614.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/12 16:46:09 2015
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

int N, M;
int main(){
    int i, j, k;
    cin>>N;
    M = N*2;
    for (i = 0; i < N; ++i) {
        int now = i;
        printf("%d", now+1);
        for (j = 1; j < M; ++j) {
            now = (now+j)%M;
            printf(" %d", now+1);
        }
        puts("");
    }
    return 0;
}
