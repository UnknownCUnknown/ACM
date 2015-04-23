/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  1/24 00:01:53 2015
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
struct A{
    int value;
    int index;
};
A a[110];
bool cmp(A x,A y){
    return x.value<y.value;
}
int ans[110];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i].value);
        a[i].index=i+1;
    }
    sort(a,a+n,cmp);
    int cnt=0;
    while(k>=a[cnt].value&&k>0){
        ans[cnt]=a[cnt].index;
        k-=a[cnt].value;
        ++cnt;
        if(cnt==n) break;
    }
    printf("%d\n",cnt);
    sort(ans,ans+cnt);
    if(cnt>0) printf("%d",ans[0]);
    for(int i=1;i<cnt;++i){
        printf(" %d",ans[i]);
    }
    if(cnt>0)printf("\n");
    return 0;
}
