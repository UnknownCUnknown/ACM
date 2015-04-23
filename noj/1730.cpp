/*************************************************************************
	> File Name: 1730.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  2/ 3 09:22:55 2015
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
int a[1010][1010];
int n;
int ans[1010][1010];
int main(){
    while(~scanf("%d",&n)){
        memset(a,0,sizeof a);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                ans[i][j]=max(ans[i-1][j],ans[i-1][j-1])+a[i][j];
            }
        }
        int res=0;
        for(int i=1;i<=n;++i){
            if(ans[n][i]>res) res=ans[n][i];
        }
        printf("%d\n",res);
    }
    return 0;
}
