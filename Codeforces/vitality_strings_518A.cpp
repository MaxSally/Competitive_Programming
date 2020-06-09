#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
    using namespace std;

int main(){
    freopen("vitality_strings_518A.txt","r",stdin);
    string a,c;
    cin >> a >> c;
        int b=a.size()-1;
        for(int i=b;i>=0;i--){
            if(a[i]<'z'){
                a[i]++;
                for(int j=i+1;j<b+1;j++){
                    a[j]='a';
                }
                break;

            }
        }
    if(a==c){
        cout << "No such string";

    }else{
        cout << a;
    }
    return 0;
}
