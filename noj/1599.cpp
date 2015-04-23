/*************************************************************************
	> File Name: 1599.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 17:43:17 2014
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
char s[1000010];
int main(){
    int num=0,alpha=0;
    while(gets(s)){
        int size=(int)strlen(s);
        for(int i=0;i<size;++i){
            if(isalpha(s[i])) ++alpha;
            else if(s[i]<='9'&&s[i]>='0') ++num;
        }
    }
    printf("%d %d\n",alpha,num);
    return 0;
}

