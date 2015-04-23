/*************************************************************************
	> File Name: 1099.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 15:35:24 2015
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
const int maxn=500000;
int Right[maxn+10];
int Left[maxn+10];
int l,r;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;++i){
        Right[i]=i+1;
        Left[i]=i-1;
    }
    l=1;
    r=n;
    for(int i=1;i<=m;++i){
        char tmp[2];
        int a,b;
        scanf("%s%d%d",tmp,&a,&b);
        if(tmp[0]=='A'){
            Left[Right[a]]=Left[a];
            if(Left[a]==0) l=Right[a];
            Right[Left[a]]=Right[a];
            if(Right[a]==n+1) r=Left[a];
            Right[Left[b]]=a;
            Left[a]=Left[b];
            if(Left[b]==0) l=a;
            Left[b]=a;
            Right[a]=b;
        }    
        else {
            Right[Left[a]]=Right[a];
            if(Right[a]==n+1) r=Left[a];
            Left[Right[a]]=Left[a];
            if(Left[a]==0) l=Right[a];
            Left[Right[b]]=a;
            if(Right[b]==n+1) r=a;
            Right[a]=Right[b];
            Left[a]=b;
            Right[b]=a;
        }
    }
    int i=Right[0];
    while(Right[i]!=n+1){
        printf("%d ",i);
        i=Right[i];
    }
    printf("%d\n",i);
    return 0;
}
