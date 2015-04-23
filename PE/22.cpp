/*************************************************************************
	> File Name: 22.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/ 5 17:11:14 2015
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
vector<string> svec;
int main(){
    string s;
    while(cin>>s){
        svec.push_back(s);
    }
    sort(svec.begin(),svec.end());
    long long cnt=1;
    long long ans=0;
    for(vector<string>::iterator i=svec.begin();i!=svec.end();++i){
        string s=*i;
        int size=s.size();
        long long tmp=0;
        for(int j=0;j<size;++j){
            tmp+=(int)(s[j]-'A'+1);
        }
        ans+=cnt*tmp;
        ++cnt;
    }
    cout<<ans<<endl;
    return 0;
}
