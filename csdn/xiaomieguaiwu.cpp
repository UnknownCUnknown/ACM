/*************************************************************************
	> File Name: xiaomieguaiwu.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日 12/14 23:13:27 2014
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
using namespace std;
int n,m;
int A[210][210];
int use[210];
int main(){
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&A[i][j]);
            }
        }
        int ans=A[0][0];
        use[0]=0;
        for(int i=1;i<n;++i){
            use[i]=i;
            ans+=A[i][i];
            for(int j=0;j<i;++j){
                int tmp=ans-A[i][use[i]]+A[i][use[j]]-A[j][use[j]]+A[j][use[i]];
                if(tmp<ans){
                    ans=tmp;
                    int temp=use[i];
                    use[i]=use[j];
                    use[j]=temp;
                }
            }
        }
        if(ans<=m)
            printf("%d\n",ans);
        else {
            printf("L will die!\n");
        }
    }
    return 0;
}
