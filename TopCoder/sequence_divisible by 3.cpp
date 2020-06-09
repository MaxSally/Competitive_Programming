//http://community.topcoder.com/stat?c=problem_statement&pm=14822

#include<stdio.h>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
    using namespace std;



int f[55][3];

class MagicNumberThree{
public:
    int countSubsequences(string s){
        int n=s.length();
        s="."+s;
        for(int i=0;i<n;i++){
            for(int r=0;r<3;r++){
                f[i][r]=0;
            }
        }
        f[0][0]=1;
        for(int i=0;i<n;i++){
            for(int r=0;r<3;r++){
                if(f[i][r]>0){
                    f[i+1][r]+=f[i][r] % 1000000007;
                    f[i+1][(r+s[i+1]-'0')%3]+=f[i][r] % 1000000007;
                }
            }
        }
        return (f[n][0]-1) % 1000000007;

    }

};

MagicNumberThree M;
int main(){
    freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    cout << M.countSubsequences(s);
    return 0;
}
