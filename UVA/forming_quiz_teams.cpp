//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=437&page=show_problem&problem=1852

#include<stdio.h>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
    using namespace std;

int n;
double f[(1<<20)];
double cost[20][20];
vector<pair<double,double> > mp;

void dynamics(){
    for(int setN=1;setN<(1<<2*n);setN++){
        double minN=1e9;
        if(__builtin_popcount(setN) % 2 ==0){
           for(int i=0;i<2*n;i++){
                for(int j=0;j<2*n;j++){
                    if(i!=j){
                        if((setN & (1<<i))==0 || (setN & (1<<j))==0){
                            continue;
                        }
                        double temp=f[setN-(1<<i)-(1<<j)]+cost[i][j];
                        if(temp<minN){
                            minN=temp;
                        }
                    }
                }
           }
            f[setN]=minN;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int ii=0;
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        mp.clear();
        for(int i=0;i<2*n;i++){
            int a,b;
            string s;
            cin >> s >> a >> b;
            //cout << s << " " << a <<" " << b <<endl;
            mp.push_back(make_pair(a,b));
        }
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                cost[i][j]=sqrt((mp[i].first-mp[j].first)*(mp[i].first-mp[j].first)+(mp[i].second-mp[j].second)*(mp[i].second-mp[j].second));
            }
        }
        f[0]=0;
        dynamics();
        ii++;
        cout << "Case " << ii<< ": " << fixed << setprecision(2) << f[(1<<2*n)-1] << endl;

    }
    return 0;
}
