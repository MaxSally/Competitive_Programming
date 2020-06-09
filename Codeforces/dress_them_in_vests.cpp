//https://codeforces.com/problemset/problem/161/A

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("dress_them_in_vests.txt","r",stdin);
    int n,m,x,y,cnt;
    cnt=0;
    cin >> n >> m >> x >> y;
    vector<int> a,b,c;
    a.resize(n+1);
    b.resize(m+1);
    c.resize(2*n+2*m);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
    int i,j,h;
    i=1;
    j=1;
    h=1;
    while(i<=n && j<=m){
        if((a[i]-x)<=b[j] && b[j]<=(a[i]+y)){
            c[h]=i;
            c[h+1]=j;
            h=h+2;
            i=i+1;
            j=j+1;
            cnt=cnt+1;
        }else if(b[j]>=(a[i]+y)){
            i++;
        }else{
            j++;
        }
    }
    cout << cnt << endl;
    for(int l=1;l<h;l=l+2){
        cout << c[l] << " " << c[l+1] << endl;
    }
    return 0;
}
