/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  4/ 5 01:08:09 2015
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
#include <iomanip>
#include <climits>
using namespace std;
long long C,a,b,c,d;
int main(){
    scanf("%lld%lld%lld%lld%lld",&C,&a,&b,&c,&d);
    long long l=0,r=C/c;
    long long ans=0;
    while(l<=r){
        long long leftmid = l+(r-l)/3;
        long long rightmid = l+2*(r-l)/3;
        long long yleft = (C-leftmid*c)/d;
        long long yright = (C-rightmid*c)/d;
        if(leftmid*a+yleft*b<rightmid*a+yright*b){
            
            l = leftmid+1;
            if(rightmid*a+yright*b>ans){
                ans = rightmid*a+yright*b;
            }
        }
        else{
            r = rightmid-1;
            if(leftmid*a+yleft*b>ans){
                ans = leftmid*a+yleft*b;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
