//http://codeforces.com/contest/1003/problem/B

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int a, b, x;
    string s;
    cin >> a >> b >> x;
    if(x % 2){
        for(int i = 0; i < x + 1; i++){
            if(!(i % 2)){
                s += "0";
            }else{
                s += "1";
            }
        }
        //cout << s << endl;
        a -= (int) (x + 1)/2;
        b -= (int) (x + 1)/2;
        string temp;
        while(a){
            temp += "0";
            a--;
        }
        s = temp + s;
        //cout << s << endl;
        string tempB;
        while(b){
            tempB += "1";
            b--;
        }
        s = s + tempB;
        //cout << s << endl;
    }else{
        bool flag = a > b;
        if(flag){
            for(int i = 0; i < x; i++){
                if(!(i % 2)){
                    s += "0";
                }else{
                    s += "1";
                }
            }
            a -= ((int) x/2) + 1;
            b -= (int) x/2;
            string temp;
            while(a){
                temp += "0";
                a--;
            }
            s = temp + s;
            string tempB;
            while(b){
                tempB += "1";
                b--;
            }
            s = s + tempB + "0";
            //s.insert(s.length() - 2, tempB);
        }else{
            for(int i = 0; i < x; i++){
                if(!(i % 2)){
                    s += "1";
                }else{
                    s += "0";
                }
            }
            b -= ((int) x/2) + 1;
            a -= (int) x/2;
            string temp;
            while(b){
                temp += "1";
                b--;
            }
            s = temp + s;
            string tempA;
            while(a){
                tempA += "0";
                a--;
            }
            s = s + tempA + "1";
        }
    }
    cout << s;
    /*for(int i = 1; i <= 100; i++){
        cout << i % 10;
    }*/
    return 0;
}
