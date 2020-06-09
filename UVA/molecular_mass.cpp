//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4461


#include<stack>
#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
    using namespace std;

int calculateMass(char a){
    if(a=='C'){
        return 12;
    }else if(a=='O'){
        return 16;
    }else if(a=='H'){
        return 1;
    }

}



int num(char a){
    return (int)(a-'0');
}

int addBracket(stack<int> &st){
    int res=0;
    while(st.top()!=-1){
        res=res+st.top();
        st.pop();
    }
    st.pop();
    return res;

}


int main(){
    freopen("molecular_mass.txt","r",stdin);
    string s;
    cin >> s;
    int a,mass;
    mass=0;
    stack<int> st;  //-1:(; -2:);
    a=s.length();
    for(int i=0;i<a;i++){
        if(isalpha(s[i])!=0){
            st.push(calculateMass(s[i]));
        }else if(s[i]=='('){
            st.push(-1);
        }else if(s[i]==')'){
            st.push(addBracket(st));
        }else{
            st.top()=st.top()*num(s[i]);
        }


    }
    while(st.empty()==false){
        mass=mass+st.top();
        st.pop();
    }

    cout << mass;
    return 0;
}
