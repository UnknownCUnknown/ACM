/*************************************************************************
	> File Name: 1001.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/22 15:23:17 2015
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
#include <iomanip>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
double ans[1000000];
double t;
int main(){
    int cnt=0;
    while(~scanf("%lf",&t)){
        ans[cnt++]=sqrt(t);
    }
    for(int i=cnt-1;i>=0;--i){
        printf("%.4f\n",ans[i]);
    }
    return 0;
}
