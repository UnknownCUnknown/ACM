/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  1/24 00:10:42 2015
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
    long long r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    long long tmp=(x1-x)*(x1-x)+(y1-y)*(y1-y);
    long long ans=ceil((double(sqrt((double)tmp)))/(2.0*(double)r));
    cout<<ans<<endl;
    return 0;
}
