//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=1265
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

const int inf = 1e9;

char s[1000005];

int main(){
    freopen("input.txt","r",stdin);
    //string s;
    int cnt = 0;
    while(gets(s)){
        cnt++;
        int q;
        cin >> q;
        cout << "Case " << cnt << ":" << endl;
        for(int i = 0; i < q; i++){
            int b, c;
            cin >> b >> c;
            if(b == c && s[b] == s[c]){
                cout << "Yes" << endl;
                continue;
            }
            bool flag = false;
            int left = min(b, c);
            int temp = max(b,c);
            for(int i = left + 1; i <= temp; i++){
                //cout << s[i] << " " << s[left] << endl;
                if(s[i] != s[left]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout <<"No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }
        getchar();
    }
    return 0;
}

