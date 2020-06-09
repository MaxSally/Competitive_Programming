//https://www.hackerrank.com/challenges/aorb/problem

#include<bits/stdc++.h>
using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl
#define Flag(n) cout << "here " << n << endl

int convert(char c){
    if((c - '0') <= 9)
        return (int)(c - '0');
    if(c == 'A') return 10;
    if(c == 'B') return 11;
    if(c == 'C') return 12;
    if(c == 'D') return 13;
    if(c == 'E') return 14;
    return 15;
}

char turnBack(int a){
    if(a < 10)
        return (char)('0' + a);
    a -= 10;
    return (char)('A' + a);
}

int reverseBit(int a, int i){
    int temp = 0;
    for(int j = 0; j < 4; j++){
        if(i == j) continue;
        temp += (1 << j);
    }
    temp &= a;
    return temp;
}



void add(string &a, int maxLength){
    while(a.length() < maxLength){
        a += "0";
    }
}

void minimize(string &a, string &b, string &c, int &moveLeft){
    for(int i = (int)a.length() - 1; i >= 0; --i){
        int a1 = convert(a[i]), b1 = convert(b[i]), c1 = convert(c[i]);
        //debug(a1); debug(b1); debug(c1);
        for(int j = 3; j >= 0; --j){
            int temp = (1 << j);
            if((c1 & temp) && (a1 & temp) && (b1 & temp) && moveLeft > 0){
                moveLeft--;
                a1 = reverseBit(a1, j);
            }
            if((c1 & temp) && (a1 & temp) && ((b1 & temp) == 0) && moveLeft > 1){
                moveLeft -= 2;
                a1 = reverseBit(a1, j);
                b1 |= temp;
            }
        }
        a[i] = turnBack(a1);
        b[i] = turnBack(b1);
    }
}

void aOrB(int k, string a, string b, string c){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    int numMove = 0;
    int maxLength = max(a.length(), max(b.length(), c.length()));
    add(a, maxLength); add(b, maxLength); add(c, maxLength);
    for(int pos = 0; pos < maxLength; ++pos){
        int a1 = convert(a[pos]), b1 = convert(b[pos]), c1 = convert(c[pos]);
        for(int i = 0; i < 4; i++){
            int temp = (1 << i);
            if(c1 & temp){
                if((a1 & temp) || (b1 & temp)){
                    continue;
                }else{
                    numMove++;
                    b1 |= temp;
                }
            }else{
                if (a1 & temp) {
                  a1 = reverseBit(a1, i);
                  numMove++;
                }
                if (b1 & temp) {
                  b1 = reverseBit(b1, i);
                  numMove++;
                }
            }
        }
        a[pos] = turnBack(a1);
        b[pos] = turnBack(b1);
    }
    if(numMove > k){
        cout << -1 << endl;
    }else{
        int moveLeft = k - numMove;
        minimize(a, b, c, moveLeft);
        while(a.back() == '0'){
            a.pop_back();
        }
        while(b.back() == '0'){
            b.pop_back();
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.empty())
        cout << 0 << endl;
        else
            cout << a << endl;
        if(b.empty())
            cout << 0 << endl;
        else
            cout << b << endl;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int q;
    cin >> q;
    while(q--){
        int k; cin >> k;
        string a, b, c; cin >> a >> b >> c;
        aOrB(k, a, b, c);
    }
    return 0;
}
