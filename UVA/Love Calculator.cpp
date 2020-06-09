//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=1365

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

const int inf = 1e9;

//`

int calculate(string s){
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i])){
            s[i] = tolower(s[i]);
            cnt += s[i] - '`';
        }
    }
    //cout << cnt << endl;
    while(cnt > 9){
        int temp = cnt;
        cnt = 0;
        while(temp){
            cnt += temp % 10;
            temp /= 10;
        }
    }
    return cnt;
}

int main(){
    freopen("input.txt","r",stdin);
    string s, t;
    while(getline(cin, s)){
        getline(cin, t);
        int a = calculate(s);
        int b = calculate(t);
        //cout << a << " " << b << endl;
        int left = min(a, b);
        int right = max(a, b);
        cout << fixed << setprecision(2) << (db) left/right*100 << " %" << endl;
    }
    return 0;
}

