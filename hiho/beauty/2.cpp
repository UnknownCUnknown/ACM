/*************************************************************************
	> File Name: 2.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  4/10 11:46:38 2015
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
long long mod=1000000007;
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int t;
        scanf("%d",&t);
        t%=mod;
        long long x=t*(t+1)/2%mod;
        long long ans=x*x%mod*x%mod+mod-(2*t+mod-2)%mod*x%mod*x%mod;
        ans%=mod;
        printf("Case %d: %d\n",ca,(int)ans);
    }
    return 0;
}
