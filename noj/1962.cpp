/*************************************************************************
	> File Name: 1962.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 23:08:44 2014
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
int f[100];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        int n;
        scanf("%d%d%d",&a,&b,&n);
        f[1]=a;
        f[2]=b;
        for(int i=3;i<=n;++i){
            if(i&1) f[i]=f[i-1]+f[i-2];
            else f[i]=f[i-1]+f[i-2]+f[i-3];
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
