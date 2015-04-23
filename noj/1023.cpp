/*************************************************************************
	> File Name: 1023.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 16:42:41 2014
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
    char s[1210];
    int index;
    int numberofA;
    void init(){
        int size=(int)strlen(s);
        numberofA=0;
        for(int i=0;i<size;++i){
            if(s[i]=='A') ++numberofA;
        }
    }
};
bool cmp(str a,str b){
    if(a.numberofA!=b.numberofA){
        return a.numberofA<b.numberofA;
    }
    else {
        return a.index<b.index;
    }
}
str datas[100];
int main(){
    int cnt=0;
    while(~scanf("%s",datas[cnt].s)){
        datas[cnt].index=cnt;
        datas[cnt].init();
        ++cnt;
    }
    sort(datas,datas+cnt,cmp);
    for(int i=0;i<cnt;++i){
        printf("%s\n",datas[i].s);
    }
    return 0;
}
