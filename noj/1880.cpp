/*************************************************************************
	> File Name: 1880.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日 12/28 10:55:56 2014
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
    while(n--){
        int tmp;
        scanf("%d",&tmp);
        ans^=tmp;
    }
    printf("%d\n",ans);
    return 0;
}
