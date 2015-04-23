/*************************************************************************
	> File Name: 18.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/ 5 12:55:26 2015
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
int ans[20][20];
int num[20][20];
int main(){
    for(int i=0;i<15;++i){
        for(int j=0;j<=i;++j){
            scanf("%d",&num[i][j]);
        }
    }
    ans[0][0]=num[0][0];
    for(int i=1;i<15;++i){
        ans[i][0]=num[i][0]+ans[i-1][0];
        ans[i][i]=num[i][i]+ans[i-1][i-1];
    }
    for(int i=1;i<15;++i){
        for(int j=1;j<i;++j){
            ans[i][j]=num[i][j]+max(ans[i-1][j-1],ans[i-1][j]);
        }
    }
    int m=0;
    for(int i=0;i<15;++i){
        if(ans[14][i]>m)m=ans[14][i];
    }
    printf("%d\n",m);
    return 0;
}
