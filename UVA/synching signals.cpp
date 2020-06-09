//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=408
/*
* Author : MaxSally
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, j, k) for (int i = j ; i <= k ; ++i)
#define rrep(i, j, k) for (int i = j; i >= k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl
#define Flag(n) cout << "here " << n << endl
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int N = 0;

int main(){
    io
    freopen("input.txt","r",stdin);
    string s;
    int cnt = 0;
    while(getline(cin, s)){
        s += " ";
        cnt++;
        int length = (int)s.length();
        vector<int> light;
        for(int i = 0; i < length; i += 3){
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            light.pb(a*10 + b);
        }
        int n = (int) light.size();
        //debuga1(light, 0, n - 1);
        vector<bool> inGreen(n, 1);
        vector<int> cntDown(n, 0);
        rep(i, 0, n - 1){
            cntDown[i] = light[i] - 5;
        }
        bool ready = 0;
        bool flagLoop = 0;
        rep(i, 0, 60){
            if(flagLoop) break;
            rep(j, 0, 59){
                if(i == 60 && j > 0) continue;
                if(i == 0 && i == j) continue;
                bool flag = 1;
                rep(k, 0, n - 1){
                    cntDown[k]--;
                    if(cntDown[k] == 0){
                        ready = 1;
                        if(inGreen[k])
                            cntDown[k] = light[k] + 5;
                        else
                            cntDown[k] = light[k] - 5;
                        inGreen[k] = !inGreen[k];
                    }
                    if(!inGreen[k]){
                        flag = 0;
                    }
                }
                if(flag && ready){
                    cout << "Set " << cnt << " synchs again at " << i << " minute(s) and " << j << " second(s) after all turning green." << endl;
                    flagLoop = 1;
                    break;
                }
            }
        }
        if(!flagLoop){
            cout << "Set " << cnt <<" is unable to synch after one hour." << endl;
        }
    }
    return 0;
}

