/*************************************************************************
	> File Name: e.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 18:48:29 2015
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
int n,tar;
int a[20];
int main(){
    scanf("%d%d",&n,&tar);
    int ans=0;
    for(int i=0;i<n;++i){
        a[i]=i+1;
    }
    do{
        ans=0;
        int sign=1;
        int i;
        for(i=0;i<n;++i){
            ans+=sign*a[i];
            if(ans>tar){
                break;
            }
            sign*=n-i-1;
            sign/=(i+1);
        }
        if(i==n&&ans==tar){
            break;
        }
    }while(next_permutation(a,a+n));
    for(int i=0;i<n-1;++i){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
    return 0;
}
