/*************************************************************************
	> File Name: try.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/16 15:38:09 2015
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
    set<int> a;
    a.insert(1);
    a.insert(0);
    a.insert(3);
    (*a.rend())=-1;
    cout<<(*a.rend())<<endl;
}
