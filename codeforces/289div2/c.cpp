/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  1/31 20:23:31 2015
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
int ans[310][310];
int main(){
    int n;
    scanf("%d",&n);
    int tmp;
    scanf("%d",tmp);
    int cnt=0;
    if(tmp%9==0){
        cnt=tmp/9;
        for(int i=0;i<cnt;++i){
            ans[i]=9;
        }
    }
    else {
        ans[0]=tmp%9;
        cnt=tmp/9;
        for(int i=1;i<cnt;++i){
            ans[i]=9;
        }
    }
    for(int i=1;i<n;++i){
        int k;
        scanf("%d",&k);
    }
}
