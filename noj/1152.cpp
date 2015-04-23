/*************************************************************************
	> File Name: 1152_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  2/ 3 09:39:38 2015
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
char s1[1010];
char s2[1010];
int main(){
    memset(s1,'\0',sizeof s1);
    while(scanf("%s",s1),s1[0]!='#'){
        scanf("%s",s2);
        int len=(int)strlen(s2);
        int cnt=0;
        char *p=s1-len;
        do{
            p=strstr(p+len,s2);
            ++cnt;
        }while(p!=NULL);
        memset(s1,'\0',sizeof s1);
        printf("%d\n",cnt-1);
    }
    return 0;
}
