/*************************************************************************
	> File Name: 1959.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  2/ 2 08:52:38 2015
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
int haha[1000];
int a[1000];
int main(){
    int n,l;
    while(~scanf("%d%d",&n,&l)){
        memset(haha,0,sizeof haha);
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            ++haha[a[i]];
        }
        int i;
        for(i=0;i<n;++i){
            if(l-a[i]>=0&&haha[l-a[i]]){
                if(a[i]==l-a[i]){
                    if(haha[a[i]]>1) printf("%d %d\n",a[i],l-a[i]);
                    else continue;
                }
                else printf("%d %d\n",a[i],l-a[i]);
                break;
            }
        }
        if(i==n) printf("NO\n");
    }
    return 0;
}
