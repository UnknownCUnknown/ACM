/*************************************************************************
	> File Name: 1167.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  1/27 08:04:35 2015
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
const int maxn=2000;
int num[1550];
int x,y,z;
int cnt=0;
void init(){
    x=y=z=0;
    num[cnt]=1;
    while(cnt<=1501){
        int a=num[x]*2;
        int b=num[y]*3;
        int c=num[z]*5;
        int m=min(a,min(b,c));
        ++cnt;
        num[cnt]=m;
        if(a==m) ++x;
        if(b==m) ++y;
        if(c==m) ++z;
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n),n){
        printf("%d\n",num[n-1]);
    }
    return 0;
}
