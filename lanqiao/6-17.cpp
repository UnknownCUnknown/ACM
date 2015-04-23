/*************************************************************************
	> File Name: 6-17.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  3/23 19:13:15 2015
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
#define eps 1e-8
class complex{
private:
    double real,vir;
public:
    complex(){
        real=0;
        vir=0;
    }
    complex(double a,double b){
        real = a;
        vir = b;
    }
    double get_real(){
        return real;
    }
    double get_vir(){
        return vir;
    }
    complex input(){
        double a;
        double b; 
        scanf("%lf%lf",&a,&b);
        real=a;
        vir=b;
        return complex(a,b);
    }
    complex operator=(complex a){
        real=a.real;
        vir=a.vir;
        return complex(real,vir);
    }
    complex operator+(complex a){
        //cout<<a.real+real;
        return complex(a.real+real,a.vir+vir);
    }
    complex operator-(complex a){
        return complex(this->real-a.real,this->vir-a.vir);
    }
    complex operator*(complex a){
        return complex(this->real*a.real-this->vir*a.vir,this->real*a.vir+this->vir*a.real);
    }
    complex operator/(complex a){
        double di=a.real*a.real+a.vir*a.vir;
        complex x=(*this)*complex(a.real,-a.vir);
        return complex(x.real/di,x.vir/di);
    }
    void out_put(){
        if(fabs(real)<=eps&&fabs(vir)<=eps){
            puts("0");
            return ;
        }
        if(fabs(real)>eps)
            printf("%g",this->real);
        if(fabs(vir)>eps){
            if(fabs(real)>eps&&vir>0){
                printf("+");
            }
            printf("%gi",vir);
        }
        printf("\n");
    }
};
char opt[4];
int main(){
    complex a,b;
    a.input();
    scanf("%s",opt);
    b.input();
    //cout<<opt[0]<<endl;
    if(opt[0]=='/'&&fabs(b.get_real())<=eps&&fabs(b.get_vir())<=eps){
        puts("error");
    } 
    else{
        complex ans;
        switch(opt[0]){
            case '+':
                ans=a+b;
                //ans.out_put();
                break;
            case '-':
                ans=a-b;
                break;
            case '*':
                ans=a*b;
                break;
            case '/':
                ans=a/b;
                break;
        }
        ans.out_put();
    }
    return 0;
}
