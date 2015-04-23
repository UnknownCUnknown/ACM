/*************************************************************************
	> File Name: 487C.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/23 22:07:16 2015
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
bool isprime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0) return false;
    }
    return true;
}
long long inv(long long a,long long m){
    if(a==1) return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1) printf("YES\n1\n");
    else if(n==4) printf("YES\n1\n3\n2\n4\n");
    else {
        if(isprime(n)){
            printf("YES\n1\n");
            for(int i=2;i<n;++i){
                printf("%I64d\n",1ll+inv(i-1,n));
            }
            printf("%d\n",n);
        }
        else printf("NO\n");
    }
    return 0;
}
