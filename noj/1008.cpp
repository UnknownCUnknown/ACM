/*************************************************************************
	> File Name: 1008.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/19 21:38:28 2014
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
int daysOFmonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int year,month,day;
    while(scanf("%d",&year)&&year!=-1){
        scanf("%d%d",&month,&day);
        int ans1=0;
        int ans2=0;
        for(int i=2000;i<year;++i){
            ans1+=365;
            if(i%400==0||(i%4==0&&i%100!=0)){
                ++ans1;
            }
        }
        if(year%400==0||(year%4==0&&year%100!=0)){
            if(month>2) {
                ++ans1;
                ++ans2;
            }
        }
        for(int i=1;i<month;++i){
            ans1+=daysOFmonth[i-1];
            ans2+=daysOFmonth[i-1];
        }
        ans1+=day-1;
        ans2+=day;
        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}
