//http://codeforces.com/problemset/problem/984/B

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector< vector<int> > a;
int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {0, 1, -1, 1, -1, 0, 1, -1};

bool minesweeper(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int b = a[i][j];
            if( b == -2){
                bool flag = true;
                for(int k = 0; k < 8; k++){
                    int x1 = i + x[k];
                    int y1 = j + y[k];
                    if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
                        continue;
                    if(a[x1][y1] == -1){
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    return false;
                else
                    continue;
            }
            if(b == -1){
                /*bool flag = true;
                for(int k = 0; k < 8; k++){
                    int x1 = i + x[k];
                    int y1 = j + y[k];
                    if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
                        continue;
                    if(a[x1][y1] > 0){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    return false;
                else
                    continue;*/
                continue;
            }
            int cnt = 0;
            for(int k = 0; k < 8; k++){
                int x1 = i + x[k];
                int y1 = j + y[k];
                if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
                    continue;
                if(a[x1][y1] == -1){
                    cnt++;
                }
            }
            if(cnt != b)
                return false;
        }
    }
    return true;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++){
        a[i].resize(m);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char b;
            int temp = 0;
            cin >> b;
            if(b == '*'){
                temp = -1;
            }else if(b == '.'){
                temp = -2;
            }else{
                temp = b - '0';
            }
            a[i][j] = temp;
        }
    }
    if(minesweeper()){
        cout << "YES";
    }else
        cout << "NO";
    return 0;
}
