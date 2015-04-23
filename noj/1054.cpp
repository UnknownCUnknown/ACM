/*************************************************************************
	> File Name: 1054.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 16:34:17 2014
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
int main(){
    while(~scanf("%s",s)){
        int size=(int)strlen(s);
        int i;
        for(i=0;i<size/2;++i){
            if(isupper(s[i])) s[i]=tolower(s[i]);
            if(isupper(s[size-1-i])) s[size-1-i]=tolower(s[i]);
            if(s[i]!=s[size-1-i]) break;
        }
        if(i==size/2){
            printf("Bingle! Palindrome.\n");
        }
        else{
            printf("Not Palindrome.\n");
        }
    }
    return 0;
}
