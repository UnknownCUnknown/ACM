/*************************************************************************
	> File Name: 1956.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 19:12:39 2015
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
char s1[1100],s2[1100];
int main(){
    memset(s1,'\0',sizeof s1);
    memset(s2,'\0',sizeof s2);
    while(~scanf("%s%s",s1,s2)){
        int size1=(int)strlen(s1);
        int size2=(int)strlen(s2);
        int size=size1>size2?size1:size2;
        for(int i=0;i<size;++i){
            if(s1[i]!='\0') printf("%c",s1[i]);
            if(s2[i]!='\0') printf("%c",s2[i]);
        }
        printf("\n");
        memset(s1,'\0',sizeof s1);
        memset(s2,'\0',sizeof s2);
    }
    return 0;
}
