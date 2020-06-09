//https://codeforces.com/problemset/problem/224/B

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("array_minimal inclusion.txt","r",stdin);
    int n,k,l,r,cnt;
    cin >> n >> k;
    vector<int> a,check;
    a.resize(n+1);
    check.resize(10*10*10*10*10+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    l=1;
    r=1;
    cnt=0;
    while(r!=n+1){
        check[a[r]]++;
        if(check[a[r]]==1){
            cnt++;
        }
        if(cnt==k){
            break;
        }
        r++;
    }

    if(cnt!=k){
        cout << -1 << " " << -1;
    }else{
        while(true){
            check[a[l]]--;
            if(check[a[l]]==0){
                break;
            }
            l++;
        }
        cout << l << " " <<r;
    }


    return 0;
}
