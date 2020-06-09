//

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("three_arrays_product.txt","r",stdin);
    int n,a1,b1,c1;
    c1=0;
    a1=0;
    b1=0;
    cin >> n;
    vector<int> a,b,c;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    vector<int>::iterator it;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num>0){
           a[a1]=num;
           a1=a1+1;

        }else if(num==0){
            c[c1]=0;
            c1=c1+1;

        }else{
            b[b1]=num;
            b1=b1+1;

        }
    }

    if(b1 % 2 ==0){
        c[c1]=b[b1-1];
        c1=c1+1;
        it=b.begin()+b1;
        b.erase(it);
        b1=b1-1;
    }
    if(a1==0){
        a[0]=b[b1-1];
        b1=b1-1;
        it=b.begin()+b1;
        b.erase(it);
        a[1]=b[b1-1];
        b1=b1-1;
        it=b.begin()+b1;
        b.erase(it);
        a1=a1+2;

    }
    a.resize(a1);
    b.resize(b1);
    c.resize(c1);
    cout << b1 << " ";
    for( int i=0;i<b1;i++){
        cout << b[i] << " ";
    }
    cout << endl << a1 << " ";
    for( int i=0;i<a1;i++){
        cout << a[i] << " ";
    }
    cout << endl << c1 << " ";
    for( int i=0;i<c1;i++){
        cout << c[i] << " ";
    }
    return 0;
}
