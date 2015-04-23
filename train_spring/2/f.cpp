/*************************************************************************
	> File Name: f.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/20 20:31:16 2015
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
double eps = 1e-8;
int main(){
    double x,y,l,w;
    while(~scanf("%lf%lf%lf%lf",&x,&y,&l,&w)){
        double low=0;
        bool flag=true;
        double high=l;
        double ans;
        while(high-low>=eps){
            double leftmid=(low+high)/2.0;
            double rightmid=(leftmid+high)/2.0;
            //cout<<mid<<endl;
            double other=sqrt(l*l-leftmid*leftmid);
            double disleft=(other*x+leftmid*y-other*leftmid)/sqrt(other*other+leftmid*leftmid);
            other=sqrt(l*l-rightmid*rightmid);
            double disright=(other*x+rightmid*y-other*rightmid)/sqrt(other*other+rightmid*rightmid);
            if(fabs(disright-disleft)<eps){
                ans=disright;
                break;
            }
            if(disright<disleft){
                low=leftmid;
                if(fabs(ans-disright)<eps) break;
                ans=disright;
            }
            else{
                high=rightmid;
                if(fabs(ans-disleft)<eps) break;
                ans=disleft;
            }
            //cout<<ans<<endl;
        }
        
        if(ans>=w) puts("yes");
        else puts("no");
    }
    return 0;
}
