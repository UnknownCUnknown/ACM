/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/20 19:01:38 2014
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
int a[1010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int sum=0;
        int sign=1;
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            sum+=a[i]*sign;
            sign=-sign;
        }
        if(sum==0){
            int i;
            for(i=0;i<n;++i){
                if(a[i]==a[n-i-1]) continue;
                else break;
            }
            if(i!=n){
                printf("Yes\n");
                continue;
            }
        }
        printf("No\n");
        
    }
    return 0;
}
