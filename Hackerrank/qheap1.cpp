//https://www.hackerrank.com/challenges/qheap1/problem

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <iomanip>
#include <assert.h>
#include <functional>
using namespace std;

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    int q;
    priority_queue<int, vector<int>, greater<int> > pq;
    priority_queue<int, vector<int>, greater<int> > pqRemove;
    cin >> q;
    int types = 0;
    int value;
    for (int i = 0; i < q; i++)
    {
        cin >> types;
        if (types == 1)
        {
            cin >> value;
            pq.push(value);
        }
        if (types == 2)
        {
            cin >> value;
            pqRemove.push(value);
        }
        if (types == 3)
        {
            while (!pqRemove.empty() && pqRemove.top() == pq.top())
            {
                pq.pop();
                pqRemove.pop();
            }
            cout << pq.top() << endl;
        }
    }
    return 0;
}
