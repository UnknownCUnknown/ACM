/*************************************************************************
	> File Name: 1005.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/19 22:33:43 2014
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
map<int,int> ans[3];
int main(){
    int a,b;
    int flag=0;
    ans[0].clear();
    ans[1].clear();
    ans[2].clear();
    while(scanf("%d%d",&a,&b)&&(a!=0||b!=-1)){
        ans[0][b]+=a;
        ans[2][b]+=a;
    }
    while(scanf("%d%d",&a,&b)&&(a!=0||b!=-1)){
        ans[1][b]+=a;
        ans[2][b]+=a;
    }
    for(int j=0;j<3;++j){
        flag=0;
        for(map<int,int>::reverse_iterator i=ans[j].rbegin();i!=ans[j].rend();++i){
            int a=(*i).second;
            int b=(*i).first;
            if(a==0) continue;
            if(a<0){
                a=-a;
                printf("-");
            }
            else if(flag){
                printf("+");   
            }
            if(a!=1){
                printf("%d",a);
            }
            else if(b==0){
                printf("%d",a);
            }
            if(b!=0){
                printf("X");
            }
            if(b>1){
                printf("^%d",b);
            }
            flag=1;
        }
        if(!flag) printf("0");
        printf("\n");
    }
    return 0;
}
