/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四 12/18 00:31:39 2014
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
int a[110];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }
    int Max=0;
    int ans=300000;
    for(int i=1;i<n-1;++i){
        Max=0;
        for(int j=0;j<n-1;++j){
            if(j!=i&&j+1!=i){
                if(a[j+1]-a[j]>Max) Max=a[j+1]-a[j];
            }
            else{
                if(j+1==i){
                    if(j+2<n&&a[j+2]-a[j]>Max) Max=a[j+2]-a[j];
                    ++j;
                }
            }
        }
        if(ans>Max) ans=Max;
    }
    printf("%d\n",ans);
    return 0;
}
