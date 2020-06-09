//http://codeforces.com/contest/1008/problem/B

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

 int main(){
     freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    int n = s.length();
    if (!(s[n - 1] == 'a' || s[n - 1] == 'e' || s[ n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u' || s[n - 1] == 'n')){
        cout << "NO";
    }else{

        bool flag = true;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'n')
                continue;
            else if(s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u')
                continue;
            else
                flag = false;
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
 }

