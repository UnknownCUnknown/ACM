/*************************************************************************
	> File Name: 1591.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 15:43:15 2014
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
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)&&(a!=0||b!=0)){
        int ans=0;
        for(int i=2;i<=a;++i) ans=(ans+b)%i;
        printf("%d\n",ans+1);
    }
    return 0;
}
