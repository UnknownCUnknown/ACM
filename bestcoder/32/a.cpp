/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  2/28 19:14:58 2015
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
long long ans;
int a[100010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int s=0,l=1;
        ans=0;
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int tmp;
        while(s<n){
            tmp=0;
            while(abs(a[l]-a[s])<=k&&l<n){
                ++tmp;
                ++l;
                ans+=tmp;
            }
            if(l==n) break;
            ++l;
            ++s;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
