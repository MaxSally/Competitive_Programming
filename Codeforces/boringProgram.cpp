#include <vector>
#include <iostream>
#include <stdio.h>
    using namespace std;

int main(){
    freopen("boringProgram.txt","r",stdin);
    int n,t,b,tf;
    vector<int> a;
    cin >> n;
    a.resize(n);
    for (int i =0;i<n; i++){
        cin >> a[i];
    }
    tf=1;
    t=0;
    b=0;
    while(tf!=0){
        if(t<90){
            if(b!=n){
                if(a[b]<=(t+15)){
                t=a[b];
                b=b+1;
              }else{
                t=t+15;
                tf=0;
              }
            }else{
                t=t+15;
                if(t>90){
                    t=90;
                }
                tf=0;
            }
        }else{
            tf=0;
            t=90;
        }
    }
    cout << t;
    return 0;
}
