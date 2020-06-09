#include <vector>
    using namespace std;
#include <iostream>
#include <stdio.h>

int main(){
    freopen("vanya_and_fence.txt","r",stdin);
    int n,h,b;
    b=0;
    cin >> n >>h;
    vector<int>a;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<=h){
            b=b+1;
        }else{
            b=b+2;
        }
    }
    cout << b;
    return 0;
}
