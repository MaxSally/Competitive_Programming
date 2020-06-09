//

#include<vector>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string>
    using namespace std;


string convert(int a,int c){
    string b="";
    while(a!=0){
        int temp=a%2 +48;
        b.push_back((char)temp);
        a=a/2;
    }
    //reverse(b.begin(), b.end());
    while(b.length()<c){
        b.push_back('0');
    }
    //cout << b <<endl;
    return b;
}

int ans(string a){
    int sum=1;
    for(int i=0;i<a.length()-1;i++){
        if(a[i]=='1'){
            sum=sum*2+1;
        }else{
            sum=sum*2;
        }
    }
    return sum;
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        int a,b;
        cin >> a >> b;
        cout << ans(convert(b-1,a)) << endl;
    }
    cin >> t;
    return 0;
}
