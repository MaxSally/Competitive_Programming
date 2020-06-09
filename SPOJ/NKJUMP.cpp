//https://vn.spoj.com/problems/NKJUMP/
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

const int N = 1005;
vii graph[N];
int n, level[N];
ll value[N];
bool visited[N];

/*int dfs(int s){
    visited[s] = 1;
    //debug(s);
    int maxDepth = 1;
    for(int a: graph[s]){
        if(visited[a]) continue;
        maxDepth = max(maxDepth, 1 + dfs(a));
    }
    //visited[s] = 0;
    return maxDepth;
}*/

int longest_path_fast_algorithm(int s){
    queue<int> q; q.push(s);
    vector<int> dist(n, inf);
    dist[s] = 0;
    vector<bool> inQueue(n, 0);
    inQueue[s] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        inQueue[u] = 0;
        for(pair<int, int> a: graph[u]){
            if(dist[u] + a.second < dist[a.first]){
                dist[a.first] = dist[u] + a.second;
                if(!inQueue[a.first]){
                    inQueue[a.first] = 1;
                    q.push(a.first);
                }
            }
        }
    }
    int maxDist = 0;
    //debuga1(dist, 0, n - 1);
    rep(i, 0, n - 1){
        if(dist[i] == inf) continue;
        maxDist = max(maxDist, -dist[i]);
    }
    return maxDist + 1;
}

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n;
    rep(i, 0, n - 1){
        cin >> value[i];
    }
    sort(value, value + n);
    mem(level, 0);
    rep(i, 2, n - 1){
        int j = 0, k = i - 1;
        ll mid = value[i], left = value[j], right = value[k];
        while(j < k && k < i){
            //debug(mid);
            //debug(left);
            //debug(right);
            if(left + right == mid){
                graph[j].pb({i, -1});
                graph[k].pb({i, -1});
                level[i] += 2;
                //Flag(0);
                while(j + 1 < k && left == value[j + 1]){
                    j++;
                    graph[j].pb({i, -1});
                    level[i]++;
                }
                while(j < k - 1 && right == value[k - 1]){
                    k--;
                    graph[k].pb({i, -1});
                    level[i]++;
                }
                j++; k--;
                left = value[j];
                right = value[k];
            }else if(left + right < mid){
                j++; left = value[j];
            }else{
                k--; right = value[k];
            }
        }
    }
    /*rep(i, 0, n - 1){
        cout << i << " " << level[i] << endl;
        rep(j, 0, (int) graph[i].size() - 1){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/
    int maxDepth = 0;
    rep(i, 0, n - 1){
        if(level[i] == 0){
            //mem(visited, 0);
            maxDepth = max(maxDepth, longest_path_fast_algorithm(i));
        }
    }
    cout << maxDepth;
    return 0;
}

