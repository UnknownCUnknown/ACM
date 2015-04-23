/*************************************************************************
	> File Name: zuidajiaodu.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 20:04:15 2014
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
typedef pair<double, double> Pos;

const int N = 1010;
const double Pi = atan2(0.0, -1.0);

double fit(double x){
    if(x > Pi){
        return x - Pi;
    }
    return x;
}

int main(void){
//  ifstream cin("in.txt");
    while(!cin.eof())
    {
        int n;
        cin >> n;
        Pos pos[N];
        vector<double> angle[N];
        for(int i = 0; i < n; i++){
            cin >> pos[i].first >> pos[i].second;
        }
        sort(pos, pos + n);
        Pos *end = unique(pos, pos + n);//去重 
        n = end - pos;//点数 
        if(n < 3){
            cout << "90.0000" << endl;
            continue;
        }
        //将每一点看成射线起点,设基准为x轴, 每条线都有一个角度 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                double at2 = atan2(pos[j].second - pos[i].second, pos[j].first - pos[i].first);
                if(at2 < 0){//角度从0到2 * Pi,方便接下来计算 
                    at2 += 2 * Pi;
                }
                angle[i].push_back(at2);
            }
        }
        for(int i = 0; i < n; i++){//把射线按与x轴的夹角排序 
            sort(angle[i].begin(), angle[i].end());
        }
        double fin[N];
        //算角差 
        for(int i = 0; i < n; i++)
        {
            double min = fit(angle[i][angle[i].size() - 1] - angle[i][0]);
            for(int j = 1; j < angle[i].size(); j++){
                double da = fit(angle[i][j] - angle[i][j - 1]);
                if(da < min){
                    min = da;
                }
            }
            fin[i] = min;
        }
        
        double max = *(max_element(fin, fin + n));
        printf("%.4f\n",max*180/Pi);
    }
    return 0;
}
