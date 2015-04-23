/*************************************************************************
	> File Name: 1501.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/30 17:44:07 2015
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
double pi=3.1415926;
int main(){
    double a,r;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf",&a,&r);
        double ans=pi*r*r;
        if(r>a){
            ans-=sqrt(3.0)/4*a*a;
        }
        else ans=ans*5.0/6.0;
        printf("%.3f\n",ans);
        getchar();
        getchar();
        getchar();
    }
    return 0;
}
