//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000100;

    int np[MAXN];

class TheRoundCityDiv1 {

    ll gres (int x, int y){
        vector <int> v;
        while (x > 1){
            int p = np[x];
            v.push_back(p);
            while (x % p == 0)
                x /= p;
        }

        int ans = 0;
        int nv = v.size();
        for (int i = 0; i < (1 << nv); i++){
            int np = 1, cv = 1;
            for (int j = 0; j < nv; j++)
                  if (i & (1 << j)){
                        cv = -cv;
                        np = np * v[j];
                  }
            ans += cv * (y / np);
        }
        return ans;
    }

    public: long long find(int r) {
          for (int i = 0; i < MAXN; i++)
                np[i] = -1;

          for (int i = 2; i < MAXN; i++){
                if (np[i] == -1){
                      for (int j = i; j < MAXN; j += i){
                            if (np[j] == -1)
                                np[j] = i;
                      }
                }
          }
          ll ans = 4;
          ll ny = r;
          for (int i = 1; i <= r; i++){
                ll nhi = r * (ll) r - i * (ll) i;
                while (ny * ny > nhi)
                    ny--;
                ans += 4 * gres (i, ny);
          }
          return ans;
    }

};
int main(){
    freopen("input.txt","r",stdin);
    TheRoundCityDiv1 a;
    int r;
    while(cin >> r){
        cout << a.find(r) << endl;;
    }
    //cin >> r;

    return 0;
}
