/*************************************************************************
	> File Name: 1069.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 02:57:18 2014
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
int ans[110];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int cnt=0;
        for(int m=1;m<=n;++m){
            int i,d,s=0;
            for(i=1;i<=n;++i) s=(s+m)%i;
            if(s+1==1){
                ans[cnt]=m;
                ++cnt;
            }
        }
        printf("%d\n",cnt);
        if(cnt>0) printf("%d",ans[0]);
        for(int i=1;i<cnt;++i){
            printf(" %d",ans[i]);
        }
        if(cnt>0) printf("\n");
    }
    return 0;
}
