/*************************************************************************
	> File Name: coderjisuanqi.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 20:54:43 2014
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
#define maxn 1000
char buf[maxn],length;

stack<char> op;
stack<double> n;

int getPriority(char c)
{
    switch(c)
    {
        case '(': return 1;
        case ')': return 1; 
        case '+': return 2;
        case '-': return 2;
        case '*': return 3;
        case '/': return 3;
        case '^': return 4;         
        default: return 0;
    }   
}

double calc(double a,double b,char c)
{
    double d; 
    switch(c)
    {
        case '+': d=(a+b); break;
        case '-': d=(a-b); break;
        case '*': d=(a*b); break;
        case '/': d=(a/b); break;
        case '^': d=pow(a,b); break;
    }
    printf("%.3lf%c%.3lf=%.3lf\n",a,c,b,d);
    return d;
}
void pull()
{
    double a,b;
    char c=op.top(); op.pop();
    if(getPriority(c)>1 && n.size()>1){
        b=n.top(); n.pop();
        a=n.top(); n.pop();
        n.push(calc(a,b,c));
    }       
} 

int main()
{
    int T,count=0;
    scanf("%d",&T);
    while(T--)
    {
        char c; double d; int i;
        length=0; count++;
        do
        {
            c=getchar();
            if(' '!=c && '\n'!=c) buf[length++]=c;
        }while('='!=c);
        
        i=-1;
        while(++i<length)
        {   
            if( buf[i]=='-' ){  //  '-' 可能出现二义性（符号或减号）因此特殊处理 
                int flag=0;
                if(i==0) flag=1;
                else if(i>0){
                    int tmp=i;
                    flag=1;
                    while(tmp--){
                        if(isalnum(buf[tmp])){
                            flag=0; break;
                        }else if(getPriority(buf[tmp])>1) break;
                    }
                }
                
                if(flag){
                    sscanf(buf+i,"%lf",&d); n.push(d);
                    while(isalnum(buf[i+1]) || '.'==buf[i+1]) i++;
                    continue;
                }               
            }
            
            if(isalnum(buf[i])){
                //从左至右扫描表达式，数字读入 
                sscanf(buf+i,"%lf",&d); n.push(d);
                while(isalnum(buf[i+1]) || '.'==buf[i+1]) i++;
            }else{
                //从左至右扫描表达式，运算符读入
                c=buf[i];
                if(getPriority(c)){ 
                    //能被识别的操作符 
                    if('('==c || '^'==c || op.empty() || getPriority(c)>getPriority(op.top()) ) op.push(c);
                    else if(')'==c){
                        //遇到有括号退栈计算，直到计算到左括号或栈空为止 
                        while(!op.empty() && '('!=op.top()) pull();
                        if(!op.empty()) op.pop();
                    }else{
                        while(!op.empty() && getPriority(c)<=getPriority(op.top())) pull(); //操作符计算 
                        op.push(c);
                    }
                } 
            }                   
        }
        
        while(!op.empty()) pull();
        printf("Case %d: %.3lf\n",count,n.top());
        while(!n.empty()) n.pop();  //清空数据栈        
    }
    
    return 0;
} 
