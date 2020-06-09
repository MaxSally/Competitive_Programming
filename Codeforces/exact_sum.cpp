//https://l.facebook.com/l.php?u=https%3A%2F%2Fuva.onlinejudge.org%2Findex.php%3Foption%3Dcom_onlinejudge%26Itemid%3D8%26category%3D24%26page%3Dshow_problem%26problem%3D1998&h=AT22xiCdguR8MRWgGpwaCWDl2J7JsLNtOvAVTkG1knd7jtVbNZXlWQMQgU6RR1sd9XPEt9mtyILKbpjGeWApFme778_pETZS33pvAtLfzo1YEjRDSq8YDH7VRLAdUhAW9Pt3TA

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n, m;
vector<int> book;

bool compare(int a, int b){
    return a < b;
}

int binarySearch(int left, int right, int tar){
    int mid = (left + right)/2;
    while(left <= right){
        if(tar == book[mid]){
            return tar;
        }
        if(book[mid] > tar){
            return binarySearch(left, mid - 1, tar);
        }
        return binarySearch(mid + 1, right, tar);
    }
    return -1;
}

int main(){
    freopen("input.txt","r",stdin);
    bool flag = true;
    while(cin >> n){
        /*if(flag){
            flag = false;
        }else{
            cout << endl;
        }*/
        book.resize(n);
        for(int i = 0; i < n; i++){
            cin >> book[i];
        }
        cin >> m;
        sort(book.begin(), book.end(), compare);
        int difference = 1e9;
        int b1 = 0;
        int b2 = 0;
        for(int i = 0; i < n; i++){
            int a = book[i];
            if(m < 2 * a){                break;
            }
            int b = binarySearch(0, n-1, m - a);
            if(b == -1){
                continue;
            }
            if(difference > b - a){
                difference = b - a;
                b1 = a;
                b2 = b;
            }
        }
        cout << "Peter should buy books whose prices are " << b1 << " and " << b2 << "." << endl;

    }
}
