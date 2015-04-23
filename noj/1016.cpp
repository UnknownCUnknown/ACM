/*************************************************************************
	> File Name: 1016.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/20 00:06:01 2014
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
string mul1(string s,char c){
    size_t size=s.size();
    string result;
    result.resize(size);
    string::size_type i=0;
    for(i=0;i<size;++i){
        result[i]=(s[i]-'0')*(c-'0');
    }
    for(i=size-1;i>0;--i){
        if(result[i]>9){
            int temp=result[i];
            result[i-1]+=temp/10;
            result[i]=temp%10+'0';
        }
        else{
            result[i]+='0';
        }
    }
    if(result[0]>9){
        int temp=result[0];
        result[0]=temp%10+'0';
        char t[2];
        t[0]=temp/10+'0';
        t[1]='\0';
        result=t+result;
    }
    else{
        result[0]+='0';
    }
    return result;
}
string add(string s1,string s2){
    int i;
    string s;
    string::size_type size1=s1.size();
    string::size_type size2=s2.size();
    if(size1<size2){
        for(i=1;i<=size2-size1;++i){
            s1="0"+s1;
        }
    }
    else{
        for(i=1;i<=size1-size2;++i){
            s2="0"+s2;
        }
    }
    string::size_type size=size1>size2?size1:size2;
    s.resize(size);
    for(i=0;i<size;++i){
        s[i]=s1[i]+s2[i]-'0';
    }
    for(i=(int)size-1;i>0;--i){
        if(s[i]>'9'){
            s[i]-=10;
            ++s[i-1];
        }
    }
    if(s[0]>'9'){
        s[0]-=10;
        s="1"+s;
    }
    return s;
}
string mul2(string s1,string s2){
    string result;
    string temp;
    size_t size=s2.size();
    int i;
    for(i=(int)size-1;i>=0;--i){
        temp=mul1(s1, s2[i]);
        temp.append(size-1-i, '0');
        result=add(result, temp);
    }
    return result;
}
string p(string s,int i){
    string result=s;
    int j;
    for(j=1;j<i;++j)
        result=mul2(result, s);
    return result;
}
string::iterator find(string::iterator i,string::iterator j,char c){
    string::iterator k;
    for(k=i;k!=j;++k){
        if(*k==c) return k;
    }
    return j;
}
int main()
{
    string s;
    int i;
    string result;
    bool flag = false;
    while(cin>>s>>i){
        flag=false;
        string::iterator j=find(s.begin(), s.end(), '.');
        string::iterator k;
        string::difference_type d=s.end()-j-1;
        if(j!=s.end()){
            s.erase(j);
            flag=true;
        }
        result=p(s,i);
        if(flag) {
            result.insert(result.end()-d*i, '.');
            for(j=result.end()-1;;--j){
                if(*j=='0') result.erase(j);
                else if(*j=='.') {
                    result.erase(j);
                    break;
                }
                else if(*j!='0') break;
            }
            k=result.begin();
            if(*k=='0'&&*(k+1)=='.') result.erase(k);
        }
        cout<<result<<endl;
    }
    return 0;
}
