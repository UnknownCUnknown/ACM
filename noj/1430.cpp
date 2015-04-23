/*************************************************************************
	> File Name: 1430.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 10:55:03 2015
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
int n,l;
int ans[25];
void dfs(int num,int step){
    ans[step]=num;
    if(step==l){
        for(int i=1;i<=step;++i){
            printf("%3d",ans[i]);
        }
        printf("\n");
        return ;
    }
    for(int i=num+1;i<=n;++i){
        dfs(i,step+1);
    } 
}
int main(){
    scanf("%d%d",&n,&l);
    dfs(0,0);
    return 0;
}
