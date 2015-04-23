/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  1/18 19:01:15 2015
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
char s[110];
int main(){
    while(gets(s)){
        int size=(int)strlen(s);
        int l=0,r=0;
        int i;
        for(i=0;i<size;++i){
            if(s[i]=='0'||s[i]=='1') continue;
            else if(s[i]=='*'){
                if(i==0) break;
                else {
                    if(s[i-1]=='('||s[i-1]=='|') break;
                }
            }
            else if(s[i]=='|'){
                if(i==0) break;
                else {
                    if(s[i-1]=='(') break;
                    if(s[i+1]=='\0'||s[i+1]=='*'||s[i+1]==')') break;
                }
            }
            else if(s[i]=='(') ++l;
            else if(s[i]==')'){
                ++r;
                if(i==0){
                    break;
                }        
                else {
                    if(s[i-1]=='(') break;
                }
            } 
            else break;
            if(r>l) break;
        }
        if(i!=size||r!=l) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
