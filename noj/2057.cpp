/*************************************************************************
	> File Name: 2057.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 23:30:17 2014
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
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double x;
        scanf("%lf",&x);
        double tmp=pow(x,3);
        double ans=tmp+3*tmp*(1.0-x)+6*tmp*(1.0-x)*(1.0-x);
        printf("%.6f\n",ans);
    }
    return 0;
}
