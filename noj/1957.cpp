/*************************************************************************
	> File Name: 1957.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  2/ 2 08:44:54 2015
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
int main(){
    int n;
    while(~scanf("%d",&n)){
        int sum=0;
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;++i){
            sum+=a[i];
            ans+=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
