/*************************************************************************
	> File Name: 2066.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  2/ 3 09:30:23 2015
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
int T;
int a[5];
int main(){
    scanf("%d",&T);
    while(T--){
        int sum=0;
        for(int i=0;i<4;++i){
            scanf("%d",a+i);
            sum+=a[i];
        }
        if(sum==0) printf("sidajiekong\n");
        else printf("%d\n",sum);
    }
    return 0;
}
