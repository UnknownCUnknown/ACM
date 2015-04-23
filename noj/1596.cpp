/*************************************************************************
	> File Name: 1596.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 16:03:30 2014
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
int mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
char week[20][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
bool isrun(int year){
    if(year%400==0) return true;
    else if(year%100==0) return false;
    else if(year%4==0) return true;
    return false;
}
int main(){
    int t;
    while(scanf("%d",&t)&&t!=-1){
        int year=1900;
        int k=t;
        while(t>=(isrun(year)?366:365)){
            t-=(isrun(year)?366:365);
            ++year;
        }
        int month=1;
        while(t>=((month==2&&isrun(year))?1:0)+mon[month-1]){
            t-=((month==2&&isrun(year))?1:0)+mon[month-1];
            ++month;
        }
        int day=t+1;
        printf("%d.%d.%d %s\n",year,month,day,week[(k)%7+1]);
    }
    return 0;
}
