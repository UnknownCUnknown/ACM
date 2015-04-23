/*************************************************************************
	> File Name: 1046.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 13:53:49 2014
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
int ans[100];
int main(){
    int n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int cnt=1;
        long long sign=9;
        while(n>sign){
            n-=sign;
            ++cnt;
            if((cnt&1)){
                sign*=10;
            }
        }
        int len=(cnt+1)/2;
        --n;
        for(int i=0;i<len;++i){
            ans[i]=n%10;
            n/=10;
        }
        ++ans[len-1];
        for(int i=len-1;i>=0;--i){
            printf("%d",ans[i]);
        }
        int now=0;
        if(cnt&1){
            now=1;
        }
        for(int i=now;i<len;++i){
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
