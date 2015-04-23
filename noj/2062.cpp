/*************************************************************************
	> File Name: 2062.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 23:36:49 2014
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
char yuan[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char mi[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
char xixixi[1100];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int len;
        scanf("%d",&len);
        scanf("%s",xixixi);
        for(int i=0;i<len;++i){
            xixixi[i]=mi[xixixi[i]-'A'];
        }
        printf("%s\n",xixixi);
    }
    return 0;
}

