//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=625&page=show_problem&problem=1199
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
pair<int,bool> a[105][15];
bool attempt[105];

struct triad{
    int problem, contest, time;
};

bool compare(triad a, triad b){
    if(a.problem == b.problem){
        if(a.time == b.time){
            return a.contest <= b.contest;
        }
        return a.time < b.time;
    }
    return a.problem > b.problem;
}

void reset(){
    rep(i, 0, 104){
        rep(j, 0, 14){
            a[i][j].first = 0;
            a[i][j].second = 0;
        }
    }
    mem(attempt, 0);
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    string s;
    int t; cin >> t;
    getline(cin, s);
    getline(cin, s);
    while(t--){
        reset();
        while(getline(cin , s), s.size() > 0){
            int contest, prob, time;
            char c;
            stringstream ss(s);
            ss >> contest >> prob >> time >> c;
            attempt[contest] = 1;
            if(a[contest][prob].second) continue;
            if(c == 'I'){
                a[contest][prob].first += 20;
            }else if(c == 'C'){
                a[contest][prob].first += time;
                a[contest][prob].second = 1;
            }
            //debug(contest); debug(prob); debug(time);
        }
        vector<triad> ans;
        rep(i, 1, 100){
            if(!attempt[i])continue;
            int prob = 0;
            int time = 0;
            rep(j, 1, 9){
                if(!a[i][j].second) continue;
                prob++;
                time += a[i][j].first;
            }
            ans.pb({prob, i, time});
        }
        sort(ans.begin(), ans.end(), compare);
        for(triad a: ans){
            cout << a.contest << " " << a.problem << " " << a.time << endl;
        }
        if(t) cout << endl;
    }
    return 0;
}

