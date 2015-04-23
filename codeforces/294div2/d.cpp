/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  3/ 2 11:23:23 2015
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
long long ty[30];
map<long long,int> v[26];
char s[100010];
int main(){
    ios::sync_with_stdio(false);
    for(int i=0;i<26;++i){
        cin>>ty[i];
    }
    cin>>s;
    int size=(int)strlen(s);
    long long tmp=0;
    long long ans=0;
    for(int i=0;i<size;++i){
        ans+=v[s[i]-'a'][tmp];
        tmp+=ty[s[i]-'a'];
        ++v[s[i]-'a'][tmp];
    }
    cout<<ans<<endl;
    return 0;
}
