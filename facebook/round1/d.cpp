/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  1/18 17:15:19 2015
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
const int N=200000;
bool a[N+10];
bool b[N+10];
int x[N+10];
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d",x+i);
        sort(x,x+n);
        int ans1=0,ans2=1;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        b[0]=true;
        for(int i=1;i<n;++i){
            a[i]=!a[x[i]-1];
            if(a[i])++ans1;
            b[i]=!b[x[i]-1];
            if(b[i])++ans2;
        }
        int ans=min(ans1,ans2)+n;
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
