//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2502

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
#define ngu cout <<"ngu" << endl;
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 1e9;

int change(string s){
    if(s == "+y"){
        return 1;
    }
    if(s == "+z")
        return 2;
    if(s == "-y")
        return 3;
    if(s == "-z")
        return 4;
}

void change_back(int state){
    if(state == 1){
        cout << "+y" << endl;
    }else if(state == 2){
        cout << "+z" << endl;
    }else if(state == 3){
        cout << "-y" << endl;
    }else if(state == 4){
        cout << "-z" << endl;
    }else if(state == 5){
        cout << "-x" << endl;
    }else{
        cout << "+x" << endl;
    }
}

int main(){
    io
    freopen("input.txt","r",stdin);
    while(true){
        int n;
        cin >> n;
        if(n == 0)
            break;
        int state = 6;
        for(int i = 0; i < n - 1; i++){
            string s;
            cin >> s;
            if(s == "No"){
                continue;
            }
            int cur = change(s);
            //change_back(state);
            if(state == 6){ // +x
                state = cur;
                continue;
            }
            if(state == 5){ // -x
                //cout << cur << " ";
                //change_back(cur);
                if(cur >=3){
                    cur -= 2;
                }else{
                    cur += 2;
                }
                state = cur;
                continue;
            }
            if(cur % 2 != state % 2){
                continue;
            }
            if(cur == state){
                state = 5;
            }else{
                state = 6;
            }
        }
        change_back(state);

    }
    return 0;
}

