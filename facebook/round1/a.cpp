/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  1/18 02:05:46 2015
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
const int maxn=10000000;
int ans[maxn+10];
void init(){
    for(int i=1;i<=maxn;++i){
        ans[i]=1;
    }
    for(int i=2;i<=maxn;++i){
        if(ans[i]==1){
            for(int j=i+i;j<=maxn;j+=i){
                ++ans[j];
            }
        }
        else --ans[i];
    }
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int cnt=0;
        for(int i=a;i<=b;++i){
            if(ans[i]==k) ++cnt;
        }
        printf("Case #%d: %d\n",ca,cnt);
    }
    return 0;
}
