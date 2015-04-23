/*************************************************************************
	> File Name: 2063.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 11:28:07 2014
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
int a[30];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int i;
        for(i=n-1;i>=2;--i){
            if(a[i]<a[i-1]+a[i-2]){
                printf("%d\n",a[i-1]+a[i-2]+a[i]);
                break;
            }
        }
        if(i==1){
            printf("-1\n");
        }
    }
    return 0;
}
