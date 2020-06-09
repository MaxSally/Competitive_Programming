#include <vector>
    using namespace std;

#include <iostream>
#include <stdio.h>

int main(){
    freopen("berland_fashion.txt","r",stdin);
    vector<int> a;
    int b;
    cin >> b;
    a.resize(b);
    for (int i =0; i<b; i++){
        cin >> a[i];
    }
    if(b==1){
        if(a[0]==1){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }else{
        int c=0;
        for(int i =0; i<b;i++){
            if(a[i]==0){
                c=c+1;
            }
        }
        if(c==1){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }
   return 0;
}
