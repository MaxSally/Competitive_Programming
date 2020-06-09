//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895
#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;


vector<long long> vec;

void heapify(int i){
    int smallest=i;
    int a=2*i+1;
    if(a<vec.size() && vec[a]<vec[smallest]){
        smallest=a;
    }
    if(a+1<vec.size() && vec[a+1]<vec[smallest]){
        smallest=a+1;
    }
    if(smallest!=i){
        swap(vec[smallest], vec[i]);
        heapify(smallest);
    }

}

void add(int b){
    vec.push_back(b);
    int i=vec.size()-1;

    while(i>=0 && vec[i]<vec[(i-1)/2]){
        swap(vec[i],vec[(i-1)/2]);
        i=(i-1)/2;
        //cout << i << endl;
    }

}

void buildHeap(){
    for(int i=vec.size()/2-1;i>=0;i--){
        heapify(i);
    }
}

void print(){
    for(int i=0;i<vec.size();i++){
       cout << vec[i]<< " ";
    }
}

void pop(){
    int len=vec.size();
    if(len==0){
        return;
    }
    vec[0]=vec[len-1];
    vec.pop_back();
    heapify(0);
}

int main(){


    while(true){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        vec.clear();
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        long long res=0;
        buildHeap();
        while(vec.size()>1){
            long long temp=vec[0];
            pop();
            temp+=vec[0];
            pop();
            add(temp);
            res+=temp;
        }
        cout << res<<endl;
    }
    return 0;
}
