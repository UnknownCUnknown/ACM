/*************************************************************************
	> File Name: 1070.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 13:32:59 2014
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
const double eps=1e-8;
const double PI = acos(-1.0);
int sgn(double x){
    if(fabs(x)<eps) return 0;
    else if (x<0) return -1;
    else return 1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x;y=_y;
    }
    Point operator-(const Point &b) const{
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const{
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b)const{
        return x*b.x+y*b.y;
    }
    void transXY(double B){
        double tx=x,ty=y;
        x=tx*cos(B)-ty*sin(B);
        y=tx*sin(B)+ty*cos(B);
    }
};
double CalcArea(Point p[],int n){
    double res=0;
    for(int i=0;i<n;++i){
        res+=(p[i]^p[(i+1)%n])/2;
    }
    return fabs(res);
}
Point p[20];
int main(){
    int T;
    scanf("%d",&T);
    double max=0;
    int maxpoint=0;
    for(int ca=1;ca<=T;++ca){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        double area=CalcArea(p,n);
        if(area>max){
            max=area;
            maxpoint = ca;
        }
    }
    printf("%d\n",maxpoint);
    return 0;
}
