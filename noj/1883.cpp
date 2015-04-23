/*************************************************************************
	> File Name: 1883.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 00:58:39 2014
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
    int a,b,c;
    int x1,y1;
    int l,r;
    while(~scanf("%d%d%d%d%d%d%d",&a,&b,&c,&x1,&y1,&l,&r)){
        double k=2*a*x1+b;
        if((2*a*x1+b)==0){
            printf("-1\n");
            continue;
        }
        double B=y1-k*x1;
        double ans=max(k*l+B,k*r+B);
        printf("%.2f\n",ans);
    }
    return 0;
}
