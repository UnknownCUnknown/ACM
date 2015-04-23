/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/30 23:11:32 2014
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
int a[310];
char s[310][310];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    for(int i=0;i<n;++i){
        scanf("%s",s[i]);
    }   
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(s[i][j]=='1'){
                if((i<j&&a[i]>a[j])||(i>j&&a[i]<a[j])){
                    int tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                    i=-1;
                }
            }
        } 
    }
    printf("%d",a[0]);
    for(int i=1;i<n;++i){
        printf(" %d",a[i]);
    }
    printf("\n");
    return 0;
}
