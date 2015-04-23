/*************************************************************************
	> File Name: shiziyouxi1.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 10:12:27 2014
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
    while(scanf("%d",&n)!=EOF){
        int sum=0;
        for(int i=0;i<n;++i){
            int tmp;
            scanf("%d",&tmp);
            sum^=tmp;
        }
        if(sum!=0){
            printf("Win\n");
        }
        else {
            printf("Lost\n");
        }
    }
    return 0;
}
