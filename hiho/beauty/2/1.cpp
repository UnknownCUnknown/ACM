/*************************************************************************
	> File Name: 1.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  4/17 10:55:44 2015
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
#include <iomanip>
#include <climits>
using namespace std;
char month[][15]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
struct date{
    int year;
    int month;
    int day;
};
int checkmonth(char *s){
    for(int i = 0;i < 12;++i){
        if (strcmp(s,month[i]) == 0) return i+1;
    }
    return -1;
}
int main(){
    int T;
    scanf("%d",&T);
    for (int ca = 1;ca <= T;++ca){
        char s[15];
        date l;
        scanf("%s %d,%d",s,&l.day,&l.year);
        l.month = checkmonth(s);
        if (l.month > 2) {
            ++ l.year;
        }
        date r;
        scanf("%s %d,%d",s,&r.day,&r.year);
        r.month = checkmonth(s);
        if (r.month < 2) {
            --r.year;
        }
        else if(r.month == 2 && r.day < 29){
            --r.year;
        }
        int ans = 0;
        int fh = r.year/400 - (l.year-1)/400;
        int oh = r.year/100 - (l.year-1)/100;
        int fd = r.year/4   - (l.year-1)/4;
        ans = fd - oh + fh;
        if (r.year < l.year) {
            ans = 0;
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
