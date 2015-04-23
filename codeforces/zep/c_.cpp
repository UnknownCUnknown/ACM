/*************************************************************************
	> File Name: c_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  4/ 5 01:27:19 2015
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
int maxn=1000000010;
int main(){
    scanf("%lld%lld%lld%lld%lld",&C,&a,&b,&c,&d);
    long long l=0,r=C/c;
    long long ans=0;
    if(r-l<=maxn){
        for(long long i=l;i<=r;++i){
            long long j=(C-i*c)/d;
            long long tmp=i*a+j*b;
            if(tmp>ans){
                ans=tmp;
            }
        }
    }
    else{
        for(long long i=0;i<=maxn;++i){
            long long x1=i;
            long long x2=(C-x1*c)/d;
            long long tmp=x1*a+x2*b;
            if(tmp>ans){
                ans=tmp;
            }
            x1=r-i;
            x2=(C-x1*c)/d;
            tmp=x1*a+x2*b;
            if(tmp>ans){
                ans=tmp;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
