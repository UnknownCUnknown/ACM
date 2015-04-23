/*************************************************************************
	> File Name: 1963.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 22:39:46 2014
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
int a[]={8,9,9,2,10};
int b[]={3,10,6,9,1};
char ans[10];
char tmp[10];
char lei[10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int max=0;
        for(int i=0;i<7;++i){
            scanf("%s",tmp);
            scanf("%s",lei);
            int le;
            scanf("%d",&le);
            int t=a[lei[0]-'A']+b[lei[0]-'A']-(le>50?(le-50)/10:0);
            if(t>max) {
                max=t;
                strcpy(ans,tmp);
            }
        }
        printf("%s\n",ans);
    }
    return 0;
}
