/*************************************************************************
	> File Name: 1013.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/19 21:52:59 2014
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
double len[5];
const double eps = (1e-3);
int main(){
    while(scanf("%lf%lf%lf",len,len+1,len+2)&&(fabs(len[0])>eps)){
        sort(len,len+3);
        if(len[0]+len[1]<=len[2]){
            printf("Not a triangle\n");
        }
        else if(fabs(len[0]-len[1])<eps&&fabs(len[1]-len[2])<eps){
            printf("Equilateral triangle\n");
        }
        else if(fabs(len[0]*len[0]+len[1]*len[1]-len[2]*len[2])<0.001){
            if(fabs(len[0]-len[1])<eps){
                printf("Isosceles right triangle\n");
            }
            else{
                printf("Right triangle\n");
            }
        }
        else if(fabs(len[0]-len[1])<eps||fabs(len[1]-len[2])<eps){
            printf("Isosceles triangle\n");
        }
        else {
            printf("General triangle\n");
        }
    }
    printf("End\n");
    return 0;
}
