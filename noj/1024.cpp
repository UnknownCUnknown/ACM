/*************************************************************************
	> File Name: 1024.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 02:26:24 2014
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
struct str{
    char a[300];
    int numofone;
    int len;
    void init(){
        int size=(int)strlen(a);
        for(int i=0;i<size;++i){
            if(a[i]=='1') ++numofone;
        }
        len=size;
    }
};
bool cmp(str a,str b){
    if(a.len!=b.len){
        return a.len<b.len;
    }
    else if(a.numofone!=b.numofone){
        return a.numofone<b.numofone;
    }
    else{
        return strcmp(a.a,b.a);
    }
}
str s[200];
int main(){
    int cnt=0;
    while(~scanf("%s",s[cnt].a)){
        s[cnt].init();
        ++cnt;
    }
    sort(s,s+cnt,cmp);
    for(int i=0;i<cnt;++i){
        printf("%s\n",s[i].a);
    }
    return 0;
}
