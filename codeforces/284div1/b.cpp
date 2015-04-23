/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四 12/25 01:46:06 2014
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
double a[5050][5050];
int p[5050];
int v[5050];
int ans[5050];
int main(){
    int n,T;
    scanf("%d%d",&n,&T);
    for(int i=0;i<n;++i){
        scanf("%d%d",&p[i],&v[i]);
        if(i==0) ans[i]=v[i];
        else ans[i]=ans[i-1]+v[i];
    }
    for(int i=0;i<=T;++i){
        for(int j=0;j<=n;++j){
            if(ans[j-1]>i){
                a[i][j]=a[i-1][j];
            }
            a[i][j]=a[i-1][j-1]*(double)p[i-1];
        }
    }
}
