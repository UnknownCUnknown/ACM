/*************************************************************************
	> File Name: 18.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/ 5 12:39:42 2015
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
string s;
int main(){
    int ans=0;
    while(cin>>s){
        ans+=s.size();
    }
    cout<<ans<<endl;
    return 0;
}
