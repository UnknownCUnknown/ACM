/*************************************************************************
	> File Name: 1095.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 02:17:19 2014
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
        int N,K;
        scanf("%d%d",&N,&K);
        memset(ans,0,sizeof ans);
        for(int i=0;i<K;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            ++ans[a];
            ++ans[b];
        }
        bool flag=true;
        for(int i=1;i<=N;++i){
            if(ans[i]==0){
                flag=false;
                break;
            }
            if(ans[i]&1){
                flag=false;
                break;
            }
        }
        if(flag){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
