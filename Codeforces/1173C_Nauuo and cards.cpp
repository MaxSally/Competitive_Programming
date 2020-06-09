//https://codeforces.com/contest/1173/problem/C
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

const int N = 200005;
vector<int> a1;
queue<int> a, tempA;
bool b[N], tempB[N];
vector<int> hand;

int main(){
    io
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    mem(b, 0);
    mem(tempB, 0);
    rep(i, 0, n - 1){
        int x; cin >> x;
        if(x != 0){
            b[x] = 1;
            tempB[x] = 1;
        }

    }
    rep(i, 0, n - 1){
        int x; cin >> x;
        a1.pb(x);
        tempA.push(x);
        a.push(x);
    }
    int pos = 1;
    int turn = 0;
    int i = 0;
    while(i < n && a1[i] != 1){
        i++;
    }
    if(i == n) i = 0;
    int pos1 = i;
    for(;i < n; i++){
        if(a1[i] == pos){
            hand.pb(pos);
            pos++;
        }else{
            break;
        }
    }
    //debuga1(hand, 0, (int)hand.size() - 1);
    bool flag = 0;
    if(i == n){
        flag = 1;
        pos = (int) hand.size() + 1;
        int posIni = pos;
        while(true){
            if(pos == n + 1) break;
            turn++;
            flag = 0;
            if(pos <= n && tempB[pos] && ((pos -posIni)  <= turn)){
                hand.pb(pos);
                pos++;
                flag = 1;
            }
            if(tempA.size()){
                int u = tempA.front(); tempA.pop();
                if(u == 0){
                    continue;
                }else{
                    tempB[u] = true;
                }
            }
            if(flag == 0){
                break;
            }
        }
    }
    if(flag){
        cout << turn;
        return 0;
    }
    pos = 1; turn = 0;
    hand.clear();
    if(pos1 != 0)
        pos1++;
    while(true){
        if(pos == n + 1) break;
        turn++;
        if(pos <= n && b[pos] && (pos <= turn - pos1)){
            //debug(turn);
            hand.pb(pos);
            pos++;
        }
        if(a.size()){
            int u = a.front(); a.pop();
            if(u == 0){
                continue;
            }else{
                b[u] = true;
            }
        }
    }
    cout << turn;
    return 0;
}

