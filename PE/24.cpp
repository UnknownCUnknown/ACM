/*************************************************************************
	> File Name: 24.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/ 5 18:34:01 2015
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
int a[]={0,1,2,3,4,5,6,7,8,9};
int main(){
    int cnt=0;
    do{
        ++cnt;
    }while(cnt!=1000000&&next_permutation(a,a+10));
    for(int i=0;i<10;++i){
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
