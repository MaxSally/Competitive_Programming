#include<vector>
#include<iostream>
#include<stdio.h>
#include<stack>
    using namespace std;

int main(){
    freopen("STPAR.txt","r",stdin);
    while(true){
        int n,c;
        cin >> n;
        if(n==0){
            break;
        }
        vector<int> a;
        a.resize(n);
        stack<int> b;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        c=1;
        for(int i=0;i<n;i++){
            if(a[i]==c){
                c++;
                while(b.empty()==false){
                    if(b.top()==c){
                        c++;
                        b.pop();
                    }else{
                        break;
                    }
                }
            }else{
                while(b.empty()==false){
                    if(b.top()==c){
                        c++;
                        b.pop();
                    }else{
                        break;
                    }
                }
                if(a[i]==c){
                    c++;
                }else{
                    b.push(a[i]);
                }

            }
        }
        if(b.empty()==false){
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
        }
    }
    return 0;
}
