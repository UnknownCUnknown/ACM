/*************************************************************************
	> File Name: 501B.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/14 16:11:35 2015
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
vector <string> svec;
vector <string> b;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    for(int ca=0;ca<T;++ca){
        string s;
        cin>>s;
        string s1;
        cin>>s1;
        vector<string>::iterator i=find(svec.begin(),svec.end(),s);
        if(i==svec.end()) {
            svec.push_back(s1);
            b.push_back(s);
        }
        else *i=s1;
    }
    int size=(int)svec.size();
    cout<<size<<endl;
    for(int i=0;i<size;++i){
        cout<<b[i]<<" "<<svec[i]<<endl;
    }
    return 0;
}
