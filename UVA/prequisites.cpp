//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=1860

#include<bits/stdc++.h>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
#define ngu cout <<"ngu" << endl;
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 1e9;

vector<int> cnt[10005];
int visited[105];


int main(){
    io
    freopen("input.txt","r",stdin);
    while(true){
        memset(visited, 0, sizeof visited);
        for(int i = 0; i < 10005; i++){
            cnt[i].clear();
        }
        int k, m;
        cin >> k;
        if(k == 0){
            break;
        }
        cin >> m;
        queue<int> q;
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            q.push(a);
        }
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            visited[i] = b;
            for(int j = 0; j < a; j++){
                int c;
                cin >> c;
                cnt[c].push_back(i);
            }
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(int i = 0; i < cnt[a].size(); i++){
                int b = cnt[a][i];
                visited[b]--;
            }
        }
        bool flag = false;
        for(int i = 0; i < k; i++){
            if(visited[i] > 0){
                flag = true;
                //cout << i << endl;
            }
        }
        if(flag){
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
        }
    }
    return 0;
}

