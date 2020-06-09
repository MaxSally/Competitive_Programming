//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2633

#include<bits/stdc++.h>
#include<string.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
#define ngu cout <<"ngu" << endl;
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 1e9;

int main(){
    io
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(t--){
        getline(cin,s);
        int cntS, cntM;
        cntS = cntM = 0;
        for(int i = 0; i < s.length(); i++){
            if(i % 3 == 2){
                continue;
            }
            if(s[i] == 'M'){
                cntM++;
            }else{
                cntS++;
            }
        }
        if(cntS == cntM && cntS > 1){
            cout <<"LOOP" << endl;
        }else{
            cout << "NO LOOP" << endl;
        }


    }
    return 0;
}

