/*************************************************************************
	> File Name: 1113.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/14 15:57:47 2015
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
int fib[40];
int main(){
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=39;++i){
        fib[i]=fib[i-1]+fib[i-2];
    }
    int T;
    scanf("%d",&T);
    int ans;
    while(T--){
        ans=0;
        int i=25;
        int k;
        scanf("%d",&k);
        while(i>=0){
            if(k>=fib[i]){
                k-=fib[i];
                if(i>1)
                    ans+=fib[i-1];
            }
            --i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
