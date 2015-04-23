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

int main()
{
    int n;

    while(cin>>n)
{

    int c=n;
    int i=0;
    int str[10010];
    while(n--)
    {
       cin>>str[i];
       i++;

    }
    sort(str,str+c);
    int b=0;
    while(b<c-1)
    {
        cout<<str[c-1]<<" "<<str[b]<<" ";
        c=c-1;
        b=b+1;
    }
    if(b==c-1)
    {
        cout<<str[b];
    }
        cout<<endl;
}
    return 0;
}
