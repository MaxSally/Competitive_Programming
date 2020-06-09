//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2708

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
        int n;
        cin >> n;
        string s;
        if(n == 0){
            break;
        }
        getline(cin, s);
        getline(cin, s);
        int ans = inf;
        vector<int> a, b;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(s[i] == 'Z'){
                flag = true;
                ans = 0;
                break;
            }else if(s[i] == 'R'){
                a.push_back(i);
            }else if(s[i] == 'D'){
                b.push_back(i);
            }
        }
        if(flag){
            cout << ans << endl;
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()){
            ans = min(ans, abs(a[i] - b[j]));
            if(a[i] > b[j])
                j++;
            else
                i++;
        }
        cout << ans << endl;
    }
    return 0;
}

