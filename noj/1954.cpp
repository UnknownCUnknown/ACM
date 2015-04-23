/*************************************************************************
	> File Name: 1954.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 16:16:46 2015
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
bool judge(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0) return false;
    }
    return true;
}
char s[1000];
int main(){
    while(~scanf("%s",s)){
        int size=(int)strlen(s);
        if(size!=3){
            printf("No\n");
            continue;
        }
        int n=0;
        bool ok=true;
        for(int i=0;i<size;++i){
            if(s[i]!=s[size-1-i]){
                ok=false;
                break;
            }
            n*=10;
            n+=s[i]-'0';
        }
        if(!ok){
            printf("No\n");
        }
        else {
            if(judge(n)){
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
    return 0;
}
