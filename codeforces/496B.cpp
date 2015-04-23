/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四 12/18 00:52:44 2014
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
char s[2100];
char ans[2100];
int len;
int main(){
    scanf("%d",&len);
    scanf("%s",s);
    strcpy(ans,s);
    for(int i=len;i<len+len;++i){
        s[i]=s[i-len];
    }
    s[len+len]='\0';
    for(int i=0;i<len;++i){
        if(s[i]=='0'){
            for(int j=i;j<len+i;++j){
                if(s[j]<ans[j-i]){
                    strncpy(ans,s+i,len);
                    break;
                }
                else if(s[j]>ans[j-i]) break;
            }
        }
        else{
            int tmp='9'-s[i]+1;
            for(int j=i;j<len+i;++j){
                int k=(s[j]+tmp-'0')%10+'0';
                if(k<ans[j-i]){
                    for(int k=i;k<len+i;++k){
                        ans[k-i]=(s[k]+tmp-'0')%10+'0';
                    }
                    break;
                }
                else if(k>ans[j-i]){
                    break;
                }
            }
        }
    }
    ans[len]='\0';
    puts(ans);
    return 0;
}
