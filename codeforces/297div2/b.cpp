/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 00:40:33 2015
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
char s[200010];
int a[100010];
int vix[100010];
int main(){
    memset(vix,0,sizeof vix);
    scanf("%s",s);
    int size=(int)strlen(s);
    //printf("%d\n",size);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
        ++vix[a[i]-1];
    }
    int tmp=0;
    for(int i=0;i<size/2;++i){
        tmp+=vix[i];
        //printf("%d",i);
        if(tmp&1){
            char temp=s[size-1-i];
            s[size-1-i]=s[i];
            s[i]=temp;
        }
    }
    printf("%s\n",s);
    return 0;
}
