/*************************************************************************
	> File Name: 1958.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  2/ 2 08:49:53 2015
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
int a[100010];
int n,k;
bool cmp(int a,int b)
{
    return a>b;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;++i) scanf("%d",a+i);
        sort(a,a+n,cmp);
        printf("%d\n",a[k-1]);
    }
    return 0;
}
