/*************************************************************************
	> File Name: 1588.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 15:31:48 2014
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
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        char c[2];
        int a,b;
        scanf("%s%d%d",c,&a,&b);
        printf("Case %d: ",ca);
        if(c[0]=='+'){
            printf("%d+%d=%d",a,b,a+b);
        }
        else if(c[0]=='-'){
            printf("%d-%d=%d",a,b,a-b);
        }
        else if(c[0]=='*'){
            printf("%d*%d=%d",a,b,a*b);
        }
        else {
            printf("%d/%d=%d",a,b,a/b);
        }
        printf("\n");
    }
    return 0;
}
