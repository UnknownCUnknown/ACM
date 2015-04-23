/*************************************************************************
	> File Name: 2043.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 19:18:54 2015
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
int a[40010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int cnt=0;
        while(a[n-1]>0){
            for(int i=0;i<m;++i){
                --a[n-i-1];
            }
            ++cnt;
            sort(a,a+n);
        }   
        printf("%d\n",cnt);
    }
    return 0;
}
