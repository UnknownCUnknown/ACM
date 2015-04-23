/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  4/ 5 00:42:00 2015
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
#include <iomanip>
#include <climits>
using namespace std;
char s[110];
int main(){
    int n;
    scanf("%d%s",&n,s);
    bool flag=false;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(s[i]=='*'&&s[j]=='*'){
                int tmp=j-i;
                int k;
                for(k=j+tmp;k<=j+3*tmp&&k<n;k+=tmp){
                    if(s[k]!='*'){
                        break;
                    }
                }
                if(k>j+3*tmp){
                    flag=true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(flag){
        puts("yes");
    }
    else{
        puts("no");
    }
    return 0;
}
