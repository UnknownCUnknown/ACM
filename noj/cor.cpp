/*************************************************************************
	> File Name: cor.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 19:22:28 2014
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
int i;
int cnt=0;
void dfs(int step,char now){
    if(step==i){
        printf(" %d\n",++cnt);
        step=0;
        return;
    }
    for(char k=now;k<='z';++k){
        printf("%c",k);
        dfs(step+1,k+1);
    }
}
int main(){
    for(i=1;i<=6;++i){
        dfs(0,'a');
    }
    return 0;
}
