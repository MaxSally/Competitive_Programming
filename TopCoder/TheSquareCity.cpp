//http://community.topcoder.com/stat?c=problem_statement&pm=14900

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <string>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
#define find dskjfkladsjfklds



class TheSquareCityDiv2{
    public: vector<int> find(int r, vector<int> t){
        int np = t.size();
        //cout << np << endl;
        int n = (int) sqrt(np);
        int a[4] = {n, -n, 1, -1};
        vector<int> numberP;
        numberP.resize(np, 0);
        for(int i = 0; i < np; i++){
            int local = i;
            int maxT = t[i];
            while(true){
                int cnt = r;
                queue<int> q;
                vector<bool> visited;
                visited.resize(np, 0);
                q.push(local);
                visited[local] = 1;
                int compareT = maxT;
                while(cnt--){
                    //cout <<"cnt " << cnt << endl;
                    int c = q.size();
                    //cout << "c " << c << endl;
                    while(c--){
                        int d = q.front();
                        //cout << "d " << d << " ";
                        q.pop();
                        for(int j = 0; j < 4; j++){
                            int e = d + a[j];
                            if(e < 0 || e >= np){
                                continue;
                            }
                            if(d % n == 0 && a[j] == -1)
                                continue;
                            if( (d + 1) % n == 0 && a[j] == 1)
                                continue;
                            //cout << e << " ";
                            if(!visited[e]){
                                visited[e] = 1;
                                q.push(e);
                                int tempT = t[e];
                                if(maxT <= tempT){
                                    maxT = tempT;
                                    local = e;
                                }
                            }
                        }
                        //cout << endl;
                    }
                }
                //cout << endl;
                if(maxT == compareT){
                    //cout << local << endl;
                    numberP[local]++;
                    break;
                }
            }
        }
        int maxN = 0;
        int cnt = 0;
        /*for(int i = 0; i < np; i++){
            cout << t[i] <<" ";
            if(t[i] < 10)
                cout << " ";
            if(t[i] < 100)
                cout << " ";
            if(i % n == n-1)
                cout << endl;
        }*/
        for(int i = 0; i < np; i++){
            /*cout << numberP[i] <<" ";
            if(i % n == n-1)
                cout << endl;*/
            if(numberP[i] != 0){
                cnt++;
                maxN = max(maxN, numberP[i]);
            }
        }
        //cout << endl;
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(maxN);
        return ans;
    }

};

int main(){
    freopen("input.txt","r",stdin);
    int n, r;
    cin >> n >> r;
    //cout << n << endl;
    vector<int> v;
    v.resize(n*n);
    for(int i = 0; i < n*n; i++){
        cin >> v[i];
    }
    TheSquareCityDiv2 q;
    vector<int> temp = q.find(r, v);
    cout << temp[0] << " " << temp[1] << endl;
    return 0;
}
