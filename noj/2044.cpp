/*************************************************************************
	> File Name: 2044.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 19:28:34 2015
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
    scanf("%d",&n);
    int ans=0;
    int now=0;
    while(n--){
        int tmp;
        scanf("%d",&tmp);
        if(tmp<0){
            if(now+tmp<0) {
                ans-=now+tmp;
                now=0;
            }
            else {
                now=now+tmp;
            }
        }
        else if(tmp>0) now+=tmp;
    }
    printf("%d\n",ans);
    return 0;
}
