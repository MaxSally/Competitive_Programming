//https://codeforces.com/contest/1183/problem/D
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
int a[N], b[N];

bool compare(int a, int b){
    return a > b;
}

void mergeA(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* create temp aays */
    int L[n1], R[n2];

    /* Copy data to temp aays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];

    /* Merge the temp aays back into a[l..r]*/
    i = 0; // Initial index of first subaay
    j = 0; // Initial index of second subaay
    k = l; // Initial index of merged subaay
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-aay of a to be sorted */
void mergeSort(int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);

        mergeA(l, m, r);
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int q; cin >> q;
    while(q--){
        int n;
        cin >> n;
        rep(i, 0, n){
            a[i] = b[i] = 0;
        }
        rep(i, 0, n - 1){
            int x; cin >> x;
            a[x]++;
        }
        rep(i, 1, n){
            b[a[i]]++;
        }
        //mergeSort(0, n);
        //debuga1(a, 0, n);
        //debuga1(b, 0, n);
        int sum = 0;
        int cnt = n;
        rrep(i, n, 1){
            if(b[i] == 0) continue;
            if(cnt == 0) break;
            cnt = min(cnt, i);
            rep(j, 1, b[i]){
                if(cnt == 0) break;
                sum += cnt;
                cnt--;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
