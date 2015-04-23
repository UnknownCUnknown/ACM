/*************************************************************************
	> File Name: 28.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/ 6 15:53:47 2015
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
int a[1100][1100];
int cx[]={0,1,0,-1};
int cy[]={1,0,-1,0};
int main(){
    int i=1;
    a[501][501]=1;
    int num=1;
    int x=501;
    int y=501;
    int cnt=1;
    while(i<=2003){
        for(int j=0;j<cnt;++j){
            x+=cx[(i-1)%4];
            y+=cy[(i-1)%4];
            a[x][y]=++num;
        }
        if(i%2==0) ++cnt;
        ++i;
    }
    int ans=0;
    for(int i=1;i<=1001;++i){
        ans+=a[i][i];
        ans+=a[i][1002-i];
    }
    printf("%d\n",ans-1);
    return 0;
}
