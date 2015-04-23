/*************************************************************************
	> File Name: g.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 20:16:02 2015
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
int n;
int ev;
bool judge(int k){
    int cnt=0;
    for(int i=0;i<n;++i){
        int tmp=cost[i]-k;
        if(tmp>0){
            cnt+=tmp/ev;
            if(tmp%ev!=0){
                ++cnt;
            }
        }
        if(cnt>k) return false;
    }
    return true;
}
int main(){
    while(~scanf("%d",&n)){
        int m=0;
        for(int i=0;i<n;++i){
            scanf("%d",cost+i);
            if(cost[i]>m){
                m=cost[i];
            }
        }
        scanf("%d",&ev);
        ev=ev-1;
        if(ev==0){
            printf("%d\n",m);
            continue;
        }
        int l=0,h=m;
        int ans=m;
        while(l<=h){
            int mid=(l+h)/2;
            if(judge(mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
