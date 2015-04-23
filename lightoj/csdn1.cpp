/*************************************************************************
	> File Name: csdn1.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/10 16:22:26 2015
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
int a[110][110];
int n,m;
struct state{
    bool is;
    int k;
    state(){}
    state(bool a,int b){
        is=a;
        k=b;
    }
}
bool flag=false;
int ans;
void dfs(int index,int t,int l,int r){
    if(index==0){
        for(int i=0;i<m;++i){
            dfs(index+1,t,a[0][i],a[0][i]);
        }
    }
}
bool judge(int t){

}
int main(){
    scanf("%d%d",&n,&m);
    int Min,Max;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
        }
    }
}
