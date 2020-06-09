//https://codeforces.com/contest/1182/problem/C
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

const int N = 1000005;

struct group{
    string s;
    int lastV, cntV, cnt;
};

int convert(char c){
    if(c == 'a') return 0;
    if(c == 'e') return 1;
    if(c == 'i') return 2;
    if(c == 'o') return 3;
    if(c == 'u') return 4;
    return -1;
}

bool compare(group a, group b){
    return a.lastV < b.lastV;
}

vector<group> gr[N];
map<string, group> mapp;
vector<pair<string,string> > complete, incomplete;
vector<vector<string> > ans;

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    rep(i, 0, n - 1){
        string t; cin >> t;
        int m = (int)t.length();
        if(mapp.find(t) != mapp.end()){
            mapp[t].cnt++;
        }
        int lastV = -1, cntV = 0;
        rrep(j, m - 1, 0){
            if(convert(t[j]) == -1) continue;
            if(lastV == -1) lastV = convert(t[j]);
            cntV++;
        }
        group g; g.lastV = lastV; g.s = t; g.cnt = 1; g.cntV = cntV;
        mapp.insert({t, g});
    }
    map<string, group>:: iterator it;
    for(it = mapp.begin(); it != mapp.end(); it++){
        group g = it->second;
        rep(i, 1, g.cnt)
            gr[g.cntV].pb(g);
        //debug(gr.s); debug(gr.lastV);
    }
    rep(i, 1, N - 1){
        int m = (int)gr[i].size();
        sort(gr[i].begin(), gr[i].end(), compare);
        vi leftOver;
        int ind = 0;
        while(ind + 1 < m){
            if(gr[i][ind].lastV == gr[i][ind + 1].lastV){
                complete.pb(mp(gr[i][ind].s, gr[i][ind + 1].s));
                ind += 2;
            }else{
                leftOver.pb(ind);
                ind++;
            }
        }
        if(ind < m) leftOver.pb(ind);
        for(int j = 0; j + 1 < (int)leftOver.size(); j += 2){
            incomplete.pb(mp(gr[i][leftOver[j]].s, gr[i][leftOver[j + 1]].s));
        }
    }
    //Flag(0);
    int ind = 0;
    for(pair<string, string> b: incomplete){
        if(ind == (int)complete.size()) break;
        vector<string> res;
        res.pb(b.first);
        res.pb(complete[ind].first);
        res.pb(b.second);
        res.pb(complete[ind].second);
        ans.pb(res);
        ind++;
    }
    while(ind + 1 < (int)complete.size()){
        vector<string> res;
        res.pb(complete[ind].first);
        res.pb(complete[ind + 1].first);
        res.pb(complete[ind].second);
        res.pb(complete[ind + 1].second);
        ans.pb(res);
        ind += 2;
    }
    cout << (int)ans.size() << endl;
    for(vector<string> res: ans){
        cout << res[0] << " " << res[1] << endl;
        cout << res[2] << " " << res[3] << endl;
    }
    return 0;
}

