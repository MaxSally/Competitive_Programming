//http://codeforces.com/problemset/problem/424/B

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
    using namespace std;

map<double,int> city;

int main(){
    freopen("megacity.txt","r",stdin);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >>c;
        double d=a*a+b*b;
        city[d]+=c;
    }
    double ans=0;
    map<double,int>::iterator it;
    for(it=city.begin();it!=city.end();it++){
        if(k>=1e6){
            break;
        }
        k+=it->second;
        ans=it->first;
    }
    if(k<1e6){
        cout << -1;
    }else{
        cout <<fixed << setprecision(7) << sqrt(ans);
    }


    return 0;
}
