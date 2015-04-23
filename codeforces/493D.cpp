/*
 * 如果是偶数则输出white 1 2
 * 如果是奇数则输出black
 */
/*************************************************************************
	> File Name: 493D.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 15:53:28 2014
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
    if(n&1){
        printf("black\n");
    }
    else {
        printf("white\n1 2\n");
    }
    return 0;
}
