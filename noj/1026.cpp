/*************************************************************************
	> File Name: 1026.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 17:32:42 2014
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
char s[20];
int a;
int main(){
    a=0;
    while(~scanf("%s",s)){
        a=0;
        int size=(int)strlen(s);
        if(size<=5){
            int i;
            for(i=0;i<size/2;++i){
                if(s[i]!=s[size-1-i]) break;
            }
            if(i!=size/2){
                printf("No\n");
                continue;
            }
            for(int i=0;i<size;++i){
                a*=10;
                a+=s[i]-'0';
            }
            bool flag=false;
            for(i=2;i*i<=a;++i){
                if(a%i==0){
                    flag=true;
                    break;
                }
            }
            if(flag||a<2){
                printf("No\n");
                continue;
            }
            else {
                printf("Yes\n");
            }
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
