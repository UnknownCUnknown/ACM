/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  1/31 20:00:55 2015
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
int a[15][15];
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
    }
    else{
        for(int i=0;i<n;++i){
            a[i][0]=a[0][i]=1;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<n;++j){
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
        printf("%d\n",a[n-1][n-1]);
    }
    return 0;
}
