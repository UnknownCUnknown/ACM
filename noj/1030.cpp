/*************************************************************************
	> File Name: 1030.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 17:56:21 2014
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
int ans1[1010];
int ans2[1010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    int tar;
    scanf("%d",&tar);
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<n;++i){
        if(a[i]>=tar){
            ans1[cnt1]=a[i];
            ++cnt1;
        }   
        else {
            ans2[cnt2]=a[i];
            ++cnt2;
        }
    }
    if(cnt2>0) printf("%d",ans2[0]);
    for(int i=1;i<cnt2;++i){
        printf(" %d",ans2[i]);
    }
    if(cnt2>0) printf(" ");
    if(cnt1>0) printf("%d",ans1[0]);
    for(int i=1;i<cnt1;++i){
        printf(" %d",ans1[i]);
    }
    printf("\n");
    sort(ans1,ans1+cnt1);
    if(cnt1>0) printf("%d",ans1[0]);
    for(int i=1;i<cnt1;++i){
        printf(" %d",ans1[i]);
    }
    printf("\n");
    return 0;
}
