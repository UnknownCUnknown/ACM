/*************************************************************************
	> File Name: aeasyproblem.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 09:46:24 2014
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
    long long a,b,x,y;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        if(a==1||b==1){
            printf("impossible.\n");
        }
        else if(a==0||b==0){
            printf("impossible.\n");
        }
        else {
            if(a>b){
                long long tmp=a;
                a=b;
                b=tmp;
            }
            long long ans=a*(b-2)-(b-a);
            if(ans==0){
                printf("impossible.\n");
            }
            else printf("%lld\n",ans);
        }
    }
    return 0;
}

