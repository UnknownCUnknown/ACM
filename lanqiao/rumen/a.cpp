/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/20 18:37:08 2014
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
int n;
int mod=10007;
int main(){
    int a,b;
    a=1;
    b=1;
    scanf("%d",&n);
    int c;
    for(int i=0;i<n-1;++i){
        c=a+b;
        c%=mod;
        a=b;
        b=c;
    }
    printf("%d\n",a);
    return 0;
} 
