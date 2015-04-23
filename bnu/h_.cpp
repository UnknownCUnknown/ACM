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
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int size=(int)strlen(s);
        int cnt=0;
        for(int i=0;i<size;++i){
            if((i<size-1)&&(((s[i]-s[i+1]==1)&&((s[i+1]-'a'+1)&1))||((s[i]-s[i+1]==-1)&&(s[i]-'a'+1)&1))){
                ++i;
            }
            else {
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
