//http://codeforces.com/contest/1015/problem/B

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
    int n;
    cin >> n;
    string s, t;
    cin >> t >> s;
    int i, j;
    i = j = 0;
    int cnt = 0;
    queue<int> q;
    while(i < n && j < n){
        if(s[i] == t[j]){
            i++;
            j++;
            continue;
        }
        int k = j + 1;
        bool flag = true;
        while(k < n){
            if(t[k] == s[i]){
                cnt += k - j;
                flag = false;
                break;
            }
            k++;
        }
        if (flag){
            cout << -1 << endl;
            return 0;
        }else{
            //char temp1 = t[j];
            //cout << t[k] << endl;
            for(int l = k; l > j; l--){
                q.push(l);
                char temp = t[l];
                t[l] = t[l - 1];
                t[l - 1] = temp;
                // cout << t << endl;
            }
            //t[k] = temp1;
            //cout << t << endl;
        }
        i++;
        j++;
    }
    cout << cnt << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
