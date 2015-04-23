/*************************************************************************
	> File Name: 1960.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  2/ 2 09:01:58 2015
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
int n,m;
int ans[20][20];
int main(){
    memset(ans,0,sizeof ans);
    for(int i=1;i<=12;++i){
        ans[i][i]=1;
        ans[i][0]=0;
    }
    for(int i=2;i<=12;++i){
        for(int j=1;j<i;++j){
            ans[i][j]=ans[i-1][j]*j+ans[i-1][j-1];
        }
    }
    while(~scanf("%d%d",&n,&m)){
        printf("%d\n",ans[n][m]);
    }
    return 0;
}
