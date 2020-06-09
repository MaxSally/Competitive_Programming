#include<vector>
#include<algorithm>
#include<iostream>
#include<stdio.h>
    using namespace std;

struct stu {
    int rating;
    int index;

};

bool compare (stu a,stu b){
    return a.rating > b.rating;
}

int main(){
    freopen("551A.txt","r",stdin);
    int n;
    cin >> n;
    vector<stu> a;
    vector<int> b;

    a.resize(n+1);
    b.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].rating;
        a[i].index=i;
    }
    sort(a.begin()+1,a.end(),compare);
    b[a[1].index]=1;
    for(int i=2;i<=n;i++){
        if(a[i].rating==a[i-1].rating){
            b[a[i].index]=b[a[i-1].index];
        }else{
             b[a[i].index]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cout << b[i] << " ";
    }

    return 0;
}


