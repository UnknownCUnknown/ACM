/*************************************************************************
	> File Name: 1031.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 02:44:54 2014
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
const int N = 1001;
int a[N],f[N],d[N];
int bsearch(const int *f,int size,const int &a){
    int l=0,r=size-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a<f[mid-1]&&a>=f[mid]) return mid;
        else if(a>f[mid]) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
int LIS(const int *a,const int &n){
    int i,j,size=1;
    f[0]=a[0];d[0]=1;
    for(i=1;i<n;++i){
        if(a[i]>=f[0]) j=0;
        else if(a[i]<f[size-1]) j=size++;
        else j=bsearch(f,size,a[i]);
        f[j]=a[i];d[i]=j+1;
    }
    return size;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    int size=LIS(a,n);
    printf("%d\n",size);
    return 0;
}
