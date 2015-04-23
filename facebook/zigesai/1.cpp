/*************************************************************************
	> File Name: 1.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/ 9 13:22:37 2015
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
char num[100];
int main(){
    int T;
    char max,min;
    int maxpoint,minpoint;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        scanf("%s",num);
        int size=(int)strlen(num);
        if(size==1&&num[0]=='0'){
            printf("Case #%d: 0 0\n",ca);
            continue;
        }
        max='0';
        min='9';
        maxpoint=minpoint=0;
        for(int i=0;i<size;++i){
            if(num[i]!='0'){
                if(num[i]>=max){
                    max=num[i];
                    maxpoint=i;
                }
                else if(num[i]<=min){
                    min=num[i];
                    minpoint=i;
                }
            }
        }
        swap(num[0],num[minpoint]);
        printf("Case #%d: %s ",ca,num);
        swap(num[0],num[minpoint]);
        swap(num[0],num[maxpoint]);
        printf("%s\n",num);
    }
    return 0;
}
