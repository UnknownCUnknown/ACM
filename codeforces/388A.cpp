/*************************************************************************
	> File Name: 388A.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/10 13:24:56 2015
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
int a[110];
bool vis[110];
int n;
int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    memset(vis,false,sizeof vis);
    sort(a,a+n);
    for(int i=0;i<n;++i){
        if(!vis[i]){
            ++ans;
            vis[i]=true;
            int cnt=1;
            for(int j=i+1;j<n;++j){
                if(!vis[j]&&a[j]>=cnt){
                    ++cnt;
                    vis[j]=true;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
