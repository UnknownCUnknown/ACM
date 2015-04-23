/*************************************************************************
	> File Name: 1406.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 03:31:06 2014
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
int a[100010];
int b[100010];
#define _cp(a,b) ((a)<(b))
typedef int elem_t;
elem_t kth_element(int n,elem_t* a,int k){// a[0...n-1]
    elem_t t,key;
    int l=0,r=n-1,i,j;
    while (l<r){
         for (key=a[((i=l-1)+(j=r+1))>>1];i<j;){
             for (j--;_cp(key,a[j]);j--);
             for (i++;_cp(a[i],key);i++);
             if (i<j) t=a[i],a[i]=a[j],a[j]=t;
         }
         if (k>j) l=j+1;
         else r=j;
    }
    return a[k];
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);    
    }
    for(int i=0;i<m;++i){
        memcpy(b,a,sizeof b);
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",kth_element(r-l+1,b+l-1,k-1));
    }
    return 0;
}
