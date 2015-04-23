/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 19:17:41 2015
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
short cnt[50000010];
int a[5];
int main(){
    for(int i=0;i<5;++i){
        scanf("%d",a+i);
    }
    for(int i=-50;i<=50;++i){
        if(i==0) continue;
        int tmp=i*i*i;
        for(int j=-50;j<=50;++j){
            if(j==0) continue;
            int k=j*j*j;
            int need=a[3]*tmp+a[4]*k;
            ++cnt[a[3]*tmp+a[4]*k+25000000];
        }
    }
    int ans=0;
    for(int i=-50;i<=50;++i){
        if(i==0) continue;
        for(int j=-50;j<=50;++j){
            if(j==0) continue;
            for(int k=-50;k<=50;++k){
                if(k==0) continue;
                int tmp=i*i*i*a[0]+j*j*j*a[1]+k*k*k*a[2];
                int need=25000000-tmp;
                if(need<0||need>50000000) continue;
                ans+=cnt[need];
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
