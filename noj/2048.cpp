/*************************************************************************
	> File Name: 2048.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 20:07:11 2015
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
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int x=sqrt(a*b/c);
    int y=sqrt(a*c/b);
    int z=sqrt(b*c/a);
    int sum=4*(x+y+z);
    printf("%d\n",sum);
    return 0;
}
