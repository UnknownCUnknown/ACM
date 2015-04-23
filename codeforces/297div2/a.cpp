/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 00:32:49 2015
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
int li[300];
char s[200010];
int main(){
    int n;
    scanf("%d%s",&n,s);
    int cnt=0;
    int ans=0;
    memset(li,0,sizeof li);
    for(int i=0;i<n-1;++i){
        ++li[s[cnt]];
        ++cnt;
        if(li[s[cnt]-'A'+'a']){
            --li[s[cnt]-'A'+'a'];
        }
        else {
            ++ans;
        }
        ++cnt;

    }
    printf("%d\n",ans);
    return 0;
}
