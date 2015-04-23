/*************************************************************************
	> File Name: 1135.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/12 14:38:22 2015
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
int n;
int num=0;
long long ans=0;
int main(){
    scanf("%d",&n);
    while(n--){
        char t;
        while(scanf("%c",&t)){
            if(t=='<'||t=='>') break;
        }
        if(t=='<') {
            ans+=num;
        }
        else{
            ++num;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
