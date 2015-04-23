/*************************************************************************
	> File Name: jinzhizhuanhuan.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 20:01:16 2014
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
#define maxn 100

char number[maxn],number_table1[maxn],number_table2[maxn],res[maxn];

void transform()
{
    int size1=strlen(number_table1),size2=strlen(number_table2);
    int value=0,mod=1;
    
    //将 number转换为10进制的值value 
    for(int i=strlen(number)-1;i>-1;i--)
    {
        int tmp=strchr(number_table1,number[i])-number_table1;
        value+=mod*tmp;
        mod*=size1;
    }
    
    int i=0; 
    while(value>0)
    {
        res[i++]=number_table2[value%size2];
        value/=size2;
    }   
    if(i==0)    res[i++]=number_table2[0];
    res[i]='\0';
    
    //字符翻转 
    for(int j=0;j<i/2;j++){
        char tmp=res[j];
        res[j]=res[i-j-1];
        res[i-j-1]=tmp;
    }   
}

int main()
{
    int T,count=0;
    scanf("%d",&T);
    while(count++<T)
    {
        scanf("%s%s%s",number,number_table1,number_table2);
        transform();
        printf("Case #%d: %s\n",count,res);
    }
    
    return 0;
}
