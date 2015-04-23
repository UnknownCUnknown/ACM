/*************************************************************************
	> File Name: 1064.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 11:48:17 2014
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
int a[100100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n-1;++i){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
    return 0;
}
