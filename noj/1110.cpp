/*************************************************************************
	> File Name: 1110.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/20 01:52:45 2014
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
int qishu[100100];
int nums[100100];
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int n;
        scanf("%d",&n);
        int cnt=0;
        memset(qishu,0,sizeof qishu);
        for(int i=0;i<n;++i){
            scanf("%d",nums+i);
            if(nums[i]&1){
                qishu[cnt]=nums[i];
                ++cnt;
            }
        }
        sort(qishu,qishu+cnt);
        int cnt2=0;
        printf("Case %d:\n",ca);
        for(int i=0;i<n-1;++i){
            if(nums[i]&1){
                printf("%d ",qishu[cnt2]);
                ++cnt2;
            }
            else {
                printf("%d ",nums[i]);
            }
        }
        if(nums[n-1]&1){
            printf("%d\n",qishu[cnt-1]);
        }
        else{
            printf("%d\n",nums[n-1]);
        }
    }
    return 0;
}
