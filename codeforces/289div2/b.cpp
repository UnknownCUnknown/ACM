/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  1/31 20:09:13 2015
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
int n,k;
int a[110];
int main(){
    scanf("%d%d",&n,&k);
    int Max=0,Min=110;
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
        if(a[i]>Max) Max=a[i];
        if(a[i]<Min) Min=a[i];
    }
    if(Max-Min>k) printf("NO\n");
    else {
        printf("YES\n");
        for(int i=0;i<n;++i){
            for(int j=0;j<a[i]-1;++j){
                printf("%d ",j%k+1);
            }
            printf("%d\n",(a[i]-1)%k+1);
        }
    }
    return 0;
}
