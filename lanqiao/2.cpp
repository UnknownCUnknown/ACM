/*************************************************************************
	> File Name: 2.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  3/23 20:08:16 2015
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
double dp[100010][110];
int main(){
    int a,b,n,x;
    scanf("%d%d%d%d",&n,&a,&b,&x);
    dp[0][0]=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<=b*n;++j){
            for(int k=a;k<=b&&j+k<=x;++k){
                dp[j+k][i+1]+=dp[j][i]*(1.0/(double)(b-a+1));
            }
        }
    }
    printf("%.4f\n",dp[x][n]);
    return 0;
}
