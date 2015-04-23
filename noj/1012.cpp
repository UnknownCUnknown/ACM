/*************************************************************************
	> File Name: 1012.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/19 21:46:41 2014
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
int ans[1000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,R;
        scanf("%d%d",&N,&R);
        if(N==0){
            printf("0\n");
            continue;
        }
        if(N<0) {
            printf("-");
            N=-N;
        }
        int cnt=0;
        while(N){
            ans[cnt]=N%R;
            ++cnt;
            N/=R;
        }
        for(int i=cnt-1;i>=0;--i){
            if(ans[i]<10) printf("%d",ans[i]);
            else printf("%c",'A'+ans[i]-10);
        }
        printf("\n");
    }
    return 0;
}
