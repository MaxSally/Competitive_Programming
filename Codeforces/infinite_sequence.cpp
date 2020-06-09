//http://codeforces.com/contest/675/problem/A

#include <iostream>

using namespace std;

const long long mod = 1000000000;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    a += mod;
    b += mod;
    int c1 = c;
    c = abs(c);
    //cout << a << " " << b << " " << c << endl;
    if(a == b){
        cout << "YES";
        return 0;
    }
    if (c == 0){
        if(a == b)
            cout << "YES";
        else
            cout << "NO";
    }
    else if(c1 < 0){
        if( a > b){
            if(b % c == a % c){
                cout <<"YES";
            }else{
                cout << "NO";
            }
        }else{
            cout << "NO";
        }
    }else{
        if( a < b){
            if(b % c == a % c){
                cout <<"YES";
            }else{
                cout << "NO";
            }
        }else{
            cout << "NO";
        }
    }


    return 0;
}


//
