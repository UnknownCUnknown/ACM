/*************************************************************************
	> File Name: 468C.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/30 18:31:35 2015
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
    long long a;
    scanf("%lld",&a);
    long long A=a;
    int cnt=0;
    while(a>=9){
        printf("9");
        a-=9;
    }
    printf("%lld\n",a);
    while(A>=9){
        printf("9");
        A-=9;
    }
    printf("%lld\n",A);
    return 0;
}
