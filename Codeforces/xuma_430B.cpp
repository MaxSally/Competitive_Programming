#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
    using namespace std;

bool compare(int a,int b){
    return a<b;
}

int main(){
    freopen("xuma_430B.txt","r",stdin);
    int n,k,x,cnt;
    cin >> n >> k >> x;
    vector<int> a;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]&& a[i]==x ){
            int l,r;
            l=i;
            r=i+1;
            while(a[l-1]==a[r+1]){
                int l1,r1;
                l1=l;
                r1=r;
                while(a[l-1]==a[l-2]&&l>=0){
                    l--;
                }
                l--;
                while(a[r+1]==a[r+2]&&r<n){
                    r++;
                }
                r++;
                if(l1-l+r-r1<3){
                    r--;
                    l++;
                    break;
                }
            }
            if(cnt<(r-l+1)){
                cnt=r-l+1;
            }
        }
    }
    cout << cnt;





    return 0;
}
