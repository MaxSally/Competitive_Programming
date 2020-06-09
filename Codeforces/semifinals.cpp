#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
    freopen("semifinal.txt","r",stdin);
    vector<int> i,j,i1,j1;
    int n;
    cin >> n;
    i.resize(n);
    j.resize(n);
    i1.resize(n);
    j1.resize(n);


    for( int a=0;a<n;a++){
        if(a<n/2){
            i1[a]=1;
            j1[a]=1;
        }else{
            i1[a]=0;
            j1[a]=0;
        }
    }
    int a,b,c;
    a=0; //all
    b=0; //i
    c=0; //j
    for(int index=0;index<n;index++){
        cin >> i[index] >> j[index];
    }

    for(a=0;a<n;a++){
       if(i[b]<=j[c]){
            i1[b]=1;
            b=b+1;
       } else{
            j1[c]=1;
            c=c+1;
        }
    }
    for(int index =0;index<n;index++){
        cout << i1[index];
    }
    cout << endl;
    for(int index =0;index<n;index++){
        cout << j1[index];
    }



    return 0;
}
