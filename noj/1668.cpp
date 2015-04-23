/*************************************************************************
	> File Name: 1668.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/28 13:08:18 2015
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
int ans[10];
int main(){
    long long a,b;
    while(~scanf("%I64d%I64d",&a,&b)){
        long long tmp=a-b;
        int cnt=0;
        int cnt1=0;
        if(tmp<0) {
            printf("-");
            tmp=-tmp;
        }
        if(tmp==0) {
            puts("0");
            continue;
        }
        while(tmp){
            ans[cnt]=tmp%10;
            tmp/=10;
            ++cnt;
            ++cnt1;
            if(cnt1%3==0){
                ans[cnt]=11;
                ++cnt;
            }
        }
        for(int i=cnt-1;i>=0;--i){
            if(ans[i]<10){
                printf("%d",ans[i]);
            }
            else if (i<cnt-1) printf(",");
        }
        printf("\n");
    }
    return 0;
}
