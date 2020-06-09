#include<iostream>
#include<stdio.h>
#include<cmath>
    using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        long long int n;
        cin >> n;
        long long int a=floor(sqrt(n));
        long long int b=n-a*a;
        //cout << a << "  "<< b << endl;
        if(b==0){
            if(a % 2 ==0){
                cout << "Case " << i << ": " << a << " " << 1 << endl;
            }else{
                cout << "Case " << i << ": " << 1 << " " << a << endl;
            }
        }else if(b<a+1){
            if(a % 2 ==0){
                cout << "Case " << i << ": " << a+1 << " " << b << endl;
            }else{
                cout << "Case " << i << ": " << b << " " << a+1 << endl;
            }

        }else{
            if(a % 2 ==0 ){
                cout << "Case " << i << ": " << a-(b-a-1)+1 << " " << a+1 << endl;
            }else{
                cout << "Case " << i << ": " << a+1 << " " << a-(b-a-1)+1 << endl;
            }

        }
    }
    return 0;
}
