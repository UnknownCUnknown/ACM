/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 18:32:11 2014
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
char ans1[]={'A','B','B','A'};
char ans2[]={'F','B','F','A'};
int main(){
    int T;
    scanf("%d",&T);
    long long n,k;
    while(T--){
        scanf("%lld%lld",&n,&k);
        if(n&1){
            ++k;
            k%=4;
            if(k==0) k=4;
            printf("%c\n",ans1[k-1]);
        }
        else {
            if(k==0){
                printf("A\n");
            }
            else {
                if(k&1){
                    printf("F\n");
                }
                else {
                    if(k%4==2){
                        printf("B\n");
                    }
                    else {
                        printf("A\n");
                    }
                }
            }
        }
    }
    return 0;
}
