/*************************************************************************
	> File Name: 1071.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/22 11:54:37 2015
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
    int n;
    while(~scanf("%d",&n)){
        if(n==0) printf("1\n");
        else if(n==1) printf("0\n");
        else if(n&1){
            printf("4");
            int k=n/2;
            while(k--) printf("8");
            printf("\n");
        }
        else {
            int k=n/2;
            while(k--) printf("8");
            printf("\n");
        }
    }
    return 0;
}
