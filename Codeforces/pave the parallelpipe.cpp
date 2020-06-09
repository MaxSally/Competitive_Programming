//http://codeforces.com/contest/1008/problem/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a, b, c;
vector<vector<int> > v;
bool m[75][75][75];
vector<int> total;

int binarySearch(int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (total[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (total[mid] > x)
            return binarySearch(l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(mid+1, r, x);
   }

   // We reach here when element is not
   // present in array
   return -1;
}

void cntFactor(){
    int cnt = 0;
    for(int i = 1; i <= a; i++){
        if(a % i == 0){
            v[0].push_back(i);
            total.push_back(i);
        }
    }
    for(int i = 1; i <= b; i++){
        if(b % i == 0){
            v[1].push_back(i);
            total.push_back(i);
        }
    }
    for(int i = 1; i <= c; i++){
        if(c % i == 0){
            v[2].push_back(i);
            total.push_back(i);
        }
    }
    vector<int> :: iterator it;
    it = unique(total.begin(), total.end());
    total.resize(distance(total.begin(), it));
    sort(total.begin(), total.end());
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < v[i].size(); j++){
            v[i][j] = binarySearch(0, total.size() - 1, v[i][j]);
        }
    }
}

int one_side(int c, int d, int e){
    int l0 = v[c].size();
    int l1 = v[d].size();
    int l2 = v[e].size();
    int cnt = 0;
    for(int i = 0; i < l0; i++){
        for(int j = 0; j < l1; j++){
            //cout << v[0][i] << " " << v[1][j] << endl;
            int x = total[v[c][i]];
            int y = total[v[d][j]];
            if(x > y)
                continue;
            for(int k = 0; k < l2; k++){
                int z = total[v[e][k]];
                if(y > z)
                    continue;
                if(m[x][y][z] == 0){
                    cnt++;
                    m[x][y][z] = 1;
                }
            }
            //cout <<"total " <<  total << endl;
        }
    }
    return cnt;
}

ll paralell(){
    ll cnt = 0;
    for(int i = 0; i < 75; i++){
        for(int j = 0; j < 75; j++){
            for(int k = 0; k < 75; k++){
                m[i][j][k] = 0;
            }
        }
    }
    cntFactor();
    cnt += one_side(0, 1, 2);
    cnt += one_side(1, 0, 2);
    cnt += one_side(0, 2, 1);
    cnt += one_side(1, 2, 0);
    cnt += one_side(2, 0, 1);
    cnt += one_side(2, 1, 0);
    total.clear();
    v[0].clear();
    v[1].clear();
    v[2].clear();
    return cnt;
}

 int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    v.resize(3);
    while(t--){
        cin >> a >> b >> c;
        //cout << a << " " << b << " " << c << endl;
        cout << paralell() << endl;
    }

    return 0;
 }

