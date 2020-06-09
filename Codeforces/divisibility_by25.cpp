//http://codeforces.com/contest/988/problem/E

#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<iomanip>
    using namespace std;

int const inf=1000*1000*1000;

string t;

int number_of_swap(){
    int ans=inf;
    int n=t.length();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            string s=t;
            int total=0;
            for(int k=i;k<n-1;k++){
                swap(s[k],s[k+1]);
                total++;
            }
            for(int k=j-(j>i);k<n-2;k++){
                swap(s[k],s[k+1]);
                total++;
            }
            int pos=1;
            for(int k=0;k<n;k++){
                if(s[k]!='0'){
                    pos=k;
                    break;
                }
            }
            for(int k=pos;k>0;k--){
                swap(s[k],s[k-1]);
                total++;
            }
            long long aa=atoll(s.c_str());
            if(aa % 25 ==0){
                ans=min(ans,total);
            }

        }
    }
    if(ans==inf){
        ans=-1;
    }
    return ans;

}

int main(){
    freopen("input.txt","r",stdin);
    long long n;
    cin >> n;
    t=to_string(n);
    cout << number_of_swap();
    return 0;
}


