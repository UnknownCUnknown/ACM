/*************************************************************************
	> File Name: 02.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  4/ 8 18:17:02 2015
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
#include <iomanip>
#include <climits>
using namespace std;
int main(){
    int a,b;
    bool flag=false;
    ios::sync_with_stdio(false);
    while(cin>>a){
        cin>>b;
        if(b==0) continue;
        if(flag){
           cout<<" "; 
        }
        else{
            flag=true;
        }
        cout<<a*b<<" "<<b-1;
    }
    if(!flag){
        cout<<"0 0";
    }
    cout<<endl;
    return 0;
}
