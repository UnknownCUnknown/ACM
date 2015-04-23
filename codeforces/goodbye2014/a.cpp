/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/30 23:03:03 2014
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
int a[30010];
int main(){
    int n,tar;
    scanf("%d%d",&n,&tar);
    for(int i=0;i<n-1;++i){
        scanf("%d",a+i);
    }
    int i=0;
    bool flag=false;
    while(i<n-1){
        if(i==tar-1) {
            flag=true;
            break;
        }
        i+=a[i];
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}
