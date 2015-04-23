/*************************************************************************
	> File Name: 1955.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  2/ 2 09:15:36 2015
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
    int sum;
    while(~scanf("%d",&sum)){
        bool flag=false;
        for(int i=1;i+i<=sum;++i){
            for(int n=2;;++n){
                int tmp=(i+n-1+i)*n/2;
                if(tmp==sum){
                    flag=true;
                    for(int j=i;j<n+i-1;++j){
                        printf("%d ",j);
                    }
                    printf("%d\n",n+i-1);
                }
                else if(tmp>sum) break;
            }
        }
        if(!flag) printf("none\n");
    }
    return 0;
}
