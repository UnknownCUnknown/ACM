/*************************************************************************
	> File Name: 1961.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  2/ 2 09:09:03 2015
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
int qpow(int x,int n,int mod){
    int result=1;
    x%=mod;
    while(n){
        if(n&1){
            result*=x;
            result%=mod;
        }
        x*=x;
        x%=mod;
        n/=2;
    }
    return result;
}
int main(){
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        printf("%d\n",qpow(a,b,1000));
    }
    return 0;

}
