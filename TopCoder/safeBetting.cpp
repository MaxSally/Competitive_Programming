//http://community.topcoder.com/stat?c=problem_statement&pm=14540&rd=16852

#include<bits/stdc++.h>
using namespace std;

class   SafeBetting{
    public: int minRounds(int a, int b, int c){
        int cnt = 1;
        int bet = b - a;
        while(b + bet < c){
            cnt++;
            //cout << b << " " << bet << endl;
            b += bet;
            bet = bet*2;
        }
        return cnt;
    };
};

int main(){
    //freopen("input.txt","r",stdin);
    SafeBetting s;
    int a, b, c;
    cin >> a >> b >> c;
    cout << s.minRounds(a, b, c);
    return 0;
}
