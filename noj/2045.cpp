/*************************************************************************
	> File Name: 2045.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 19:35:45 2015
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
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int n;
        scanf("%d",&n);
        int sum=0;
        int ans=0;
        int l=0,r=0;
        int ansl=0;
        int tmp;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            if(i==0){
                ans=tmp;
            }
            sum+=tmp;
            if(sum<0) {
                sum=0;
                l=i+1;
            }
            if(sum>ans){
                ans=sum;
                ansl=l;
                r=i;
            }
        }
        printf("Case %d:\n%d %d %d\n",ca,ans,ansl+1,r+1);
        if(ca!=T) printf("\n");
    }
    return 0;
}
