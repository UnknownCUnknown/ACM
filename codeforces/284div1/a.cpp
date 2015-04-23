/*
 * 对于每条线，如果两个点分别位于这条线的两侧，则对答案+1。
 * 因为一个点要到另一个点，必须要穿过这条线，而每次只能穿过1条线。
 * 就是这样。
 */
/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四 12/25 00:39:09 2014
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
    long long x,y;
    long long x1,y1;
    scanf("%lld%lld%lld%lld",&x,&y,&x1,&y1);
    int n;
    scanf("%d",&n);
    long long cnt=0;
    while(n--){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a*x+b*y+c>0){
            if(a*x1+b*y1+c<0) ++cnt;
        }
        else {
            if(a*x1+b*y1+c>0) ++cnt;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}
