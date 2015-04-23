/*************************************************************************
	> File Name: 1151.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/28 13:21:34 2015
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
    while(scanf("%d",&n),n){
        int ans=0;
        scanf("%d",&ans);
        for(int i=1;i<n;++i){
            int tmp;
            scanf("%d",&tmp);
            ans^=tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
