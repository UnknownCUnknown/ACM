/*************************************************************************
	> File Name: 1050.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/20 01:49:11 2014
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
char s[10010];
int main(){
    scanf("%s",s);
    int size=(int)strlen(s);
    long long sum=0;
    for(int i=0;i<size;++i){
        sum+=(long long)(s[i]-'0');
    }
    printf("%lld\n",sum);
    return 0;
}
