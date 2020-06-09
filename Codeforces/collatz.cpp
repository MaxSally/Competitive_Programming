#include <bits/stdc++.h>
#define MAX_N 100100
using namespace std;

ll x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    //freopen("input.txt", "r" , stdin);

    cin >> test;

    while (test--)
    {
        cin >> x;

        cout << x - (x / 2) + ((x + 1) / 2) - (((x - 1) / 3) + 1) / 2 << endl;
    }

    return 0;
}
