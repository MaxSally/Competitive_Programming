#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
    using namespace std;

bool compare(int a,int b){
    return a<b;
}

int main(){
    freopen("451B.txt","r",stdin);
    int n,l,r;
    cin >> n;
    l=1;
    r=n;
    vector<int> a,b;
    a.resize(n+1);
    b.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    sort(a.begin()+1,a.end(),compare);
    while(b[l]<b[l+1] && l<n){
        l++;
    }
    while(b[r-1]<b[r] && r>0){
        r--;
    }

    if(l>=r){
        cout << "yes" << endl << 1 << " " <<1;
    }else{
        reverse(b.begin()+l,b.begin()+r+1);
        int cnt;
        cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==b[i]){
                cnt++;
            }
        }
        if(cnt==n){
            cout << "yes" << endl << l << " " << r;
        }else{
            cout << "no";
        }
    }

    return 0;
}

