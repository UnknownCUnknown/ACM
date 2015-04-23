/*************************************************************************
	> File Name: 1503.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/30 17:33:14 2015
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
struct bug{
    long long value;
    long long cost;
};
int cmp(bug a, bug b){
    return a.value*b.cost<a.cost*b.value;
}
bug b[100010];
int main(){
    int n;
    long long sum;
    while(~scanf("%d",&n)){
        sum=0;
        for(int i=0;i<n;++i) {
            scanf("%I64d%I64d",&b[i].value,&b[i].cost);
            sum+=b[i].cost;
        }    
        sort(b,b+n,cmp);
        long long ans=0;
        for(int i=0;i<n;++i){
            ans+=sum*b[i].value;
            sum-=b[i].cost;
        }
        printf("%I64d\n",ans);
    }               
    return 0;
}
