/*************************************************************************
	> File Name: 1027.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 16:56:29 2014
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
char s[300];
long long sum=0;
int main(){
    while(gets(s)){
        if(s[0]=='#') break;
        else{
            sum=0;
            int size=(int)strlen(s);
            for(int i=0;i<size;++i){
                if(isupper(s[i]))
                    sum+=(i+1)*(s[i]+1-'A');
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}
