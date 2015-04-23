/*************************************************************************
	> File Name: k.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/13 14:53:37 2015
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
long long a[1100][1100];
int main(){
    a[0][0]=1;
    for(int i=1;i<=900;++i){
        for(int j=0;j<=i;++j){
            if(j==0) a[i][j]=1;
            else if(j==i) a[i][j]=1;
            else a[i][j]=a[i-1][j]+a[i-1][j-1];
            if(a[i][j]==10) {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}
