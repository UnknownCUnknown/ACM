/*************************************************************************
	> File Name: f.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 18:59:24 2015
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
int cost[100010];
int n,month;
int m=0;
bool judge(int k){
    int tmp=0;
    int cnt=0;
    for(int i=0;i<n;++i){
        if(tmp+cost[i]>k){
            tmp=cost[i];
            ++cnt;
            if(cnt>month) return false;
        }
        else{
            tmp+=cost[i];
        }
    }
    ++cnt;
    if(cnt>month) return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&month);
    int sum=0;

    for(int i=0;i<n;++i){
        scanf("%d",cost+i);
        if(m<cost[i]){
            m=cost[i];
        }
        sum+=cost[i];
    }
    int l=m,h=sum;
    int ans=sum;
    while(l<=h){
        int mid = (l+h)/2;
        if(judge(mid)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
