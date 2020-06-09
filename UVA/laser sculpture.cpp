//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2730

#include<bits/stdc++.h>
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
    while(true){
        int a, c;
        cin >> a;
        if(a == 0){
            break;
        }
        cin >> c;
        int cnt = 0;
        int height;
        cin >> height;
        int cur = height;
        for(int i = 1; i < c; i++){
            int b;
            cin >> b;
            if(b > cur && b > height){
                cnt += b - max(height, cur);
                height = b;
            }else if( b < cur){
                cnt += cur - b;
            }
            cur = b;
            //cout << cnt << endl;
        }
        cout << cnt + (a - max(height, cur)) << endl;
    }
    return 0;
}

