/*************************************************************************
	> File Name: 1111.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 03:21:17 2014
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
char First[210];
char tar[210];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s %s",First,tar);
        int size=(int)strlen(First);
        int ans=0;
        for(int i=0;i<size;++i){
            if(First[i]!=tar[i]){
                ++ans;
                int j=i+1;
                while(1){
                    if(First[j]!=First[i]||First[j]==tar[j]) break;
                    else ++j;
                }
                i=j-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
