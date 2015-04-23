/*************************************************************************
	> File Name: 1129.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/21 07:59:53 2015
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
vector<int> ivec[30];
char s[100];
int ans[100];
int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i) ivec[i].clear();
        for(int i=0;i<n;++i){
            char tmp;
            scanf("%c:%s",tmp,s);
            int size=(int)strlen(s);
            for(int j=0;j<n;++j){
                if(s[j]<tmp){
                    ivec[tmp-'A'].push_back(s[j]-'A');
                }
            }
        }
        memset(ans,0,sizeof ans);
        ans[0]=1;
        int res=1;
        for(int i=1;i<n;++i){
            
        }
    }
}
