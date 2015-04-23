/*************************************************************************
	> File Name: h.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 18:45:06 2014
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
char s[100100];
char ans[100100];
int isaway[100100];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int size=(int)strlen(s);
        int cnt=0;
        memset(isaway,0,sizeof isaway);
        for(int i=0;i<size;++i){
            if((i<size-1)&&((s[i]-'a'+1)&1)&&(s[i]-s[i+1]==1||s[i]-s[i+1]==-1)){
                isaway[i]=1;
                isaway[i+1]=1;
            }
            else if(!isaway[i]){
                ans[cnt]=s[i];   
                ++cnt;
            }
        }
        if(cnt==0){
            printf("sad!\n");
            continue;
        }
        ans[cnt]='\0';
        printf("%s\n",ans);
    }
    return 0;
}

