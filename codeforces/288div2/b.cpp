/*
 * 首先，输入是一个奇数，所以不用考虑换位后产生前导0，且要产生偶数一定是最后一个数和前面的数交换。
 * 然后，前面若是没有偶数，则输出-1。
 * 前面若是有比最后一个数大的偶数，则交换后整个数增大，所以越靠前增大的越多。
 * 前面若是没有比最后一个数大的偶数，则交换后整个数减小，所以越靠后减小的越小。
 */
/*************************************************************************
	> File Name: b_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/28 01:17:13 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
char s1[100010];
int main(){
    scanf("%s",s1);
    int size=(int)strlen(s1);
    int point1=-1;
    int point2=-1;
    for(int i=0;i<size-1;++i){
        if((s1[i]-'0')%2==0){
            point2=i;
            if(point1==-1&&s1[i]<s1[size-1]){
                point1=i;
            }
        }
    }
    if(point2==-1) puts("-1");
    else {
        if(point1!=-1){
            swap(s1[size-1],s1[point1]);
            puts(s1);
        }
        else {
            swap(s1[size-1],s1[point2]);
            puts(s1);
        }
    }
    return 0;
}
