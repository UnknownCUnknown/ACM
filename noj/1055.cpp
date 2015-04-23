/*************************************************************************
	> File Name: 1055.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/19 21:29:49 2014
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
int f(int a){
    int cnt=0;
    if(a==1){
        a=4;
        cnt=1;
    }
    while(a!=1){
        if(a&1) a=a*3+1;
        else a/=2;
        ++cnt;
    }
    return cnt;
}
int main(){
    int T;
    scanf("%d",&T);
    
    for(int i=0;i<T;++i){
        int tmp;
        scanf("%d",&tmp);
        printf("%s",f(tmp)&1?"I win!\n":"I lost!\n");
    }
    return 0;
}
