/*************************************************************************
	> File Name: 1098.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 15:13:56 2015
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
stack<int> st;
int a[1010];
int main(){
    int n;
    //int ok=0;
    while(scanf("%d",&n),n){
        //if(ok) printf("\n");
        //else ok=1;
        while(scanf("%d",a+1),a[1]){
            while(!st.empty()) st.pop();
            for(int i=2;i<=n;++i){
                scanf("%d",a+i);
            }
            int cnt=1;
            for(int i=1;i<=n;++i){
                st.push(i);
                while(!st.empty()&&st.top()==a[cnt]){
                    st.pop();
                    ++cnt;
                }
            }
            if(st.empty()){
                printf("Yes\n");
            }
            else printf("No\n");
        }   
        printf("\n");
    }
    return 0;
}
