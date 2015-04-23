/*************************************************************************
	> File Name: e.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日 12/21 14:22:50 2014
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
bool isko[1010];
int main(){
    int k,d,n;
    while(~scanf("%d%d%d",&n,&k,&d)){
        memset(isko,false,sizeof isko);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int cnt=0;
        for(int i=0;i<n;++i){
            if(!isko[i]){
                for(int j=i;j<n;++j){
                    if((a[j]-a[i])%d==0&&(a[j]-a[i])/d<k){
                        isko[j]=true;
                    }
                }
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }       
    return 0;
}
