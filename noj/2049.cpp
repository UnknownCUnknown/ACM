/*************************************************************************
	> File Name: 2049.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 20:11:26 2015
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
int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    int sum=0;
    int t;
    int n_=n;
    while(n_--){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==0){
            ++sum;   
        }
        else {
            --sum;
            ++t;
        }
        if(sum<0) sum=0;
        if(sum>ans) ans=sum;
    }
    if(t==n) ans=-1;
    printf("%d\n",ans+t);
    return 0;
}
