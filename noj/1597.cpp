/*************************************************************************
	> File Name: 1597.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 17:57:41 2014
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
int n,m,k;
int iskill[110];
int main(){
    int ca = 1;
    while(scanf("%d%d%d",&n,&m,&k)&&(n!=0||m!=0||k!=0)){
        int cnt=0;
        int num=0;
        memset(iskill,0,sizeof iskill);
        int i=0;
        while(1){
            if(!iskill[i]){
                ++cnt;
                if(cnt==k){
                    ++num;
                    iskill[i]=1;
                    if(num==m) break;
                    cnt=0;
                }
            }
            ++i;
            if(i==n) i=0;
        }
        printf("Case %d:",ca);
        ++ca;
        for(int i=0;i<n;++i){
            if(iskill[i]) printf(" %d",i+1);
        }
        printf("\n");
    }
    return 0;
}
